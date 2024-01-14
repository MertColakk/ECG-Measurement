#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ECG.hpp"
#define DIVIDED 0.000125

int patientCount=0;
        //Patient Class Operations
//Constructor
Patient::Patient(){
    this->voltages.clear();
    this->times.clear();

    this->timePoint.clear();
    this->peakIdx.clear();
    this->bradikardiIdx.clear(); 
    this->tasikardiIdx.clear();
    this->normalIdx.clear(); 
    this->signalPoint.clear();

    this->result=" ";

    this->peakCount=0;

    this->hearthRate=0.0;
    this->peakDelay = 0.1 / 0.000125;
}

//Other Functions
void Patient::readData(std::string fileName){
    //Variables
    std::ifstream dataFile(fileName);
    std::string timeString,voltageString;
    std::string fileLine;

    if(!dataFile.is_open()){
        std::cout<<"There is an error while reading the data file!"<<std::endl;
        return;
    }

    //Clearing vectors for better results
    this->times.clear();
    this->voltages.clear();

    while(std::getline(dataFile,fileLine)){
        std::istringstream lineStream(fileLine);

        if(!(lineStream>>timeString>>voltageString)){
            std::cout<<"Error while taking the lines from file!"<<std::endl;
            return;
        }
            
        this->times.push_back(std::stod(timeString));//converting to double
        this->voltages.push_back(std::stod(voltageString));
    }

    std::cout<<"Patient's datas has been read."<<std::endl;
    dataFile.close();

}
void Patient::findPeakCount(){
    const double threshold = 0.1; 
    for (int i = 1; i < voltages.size() - 1; ++i)
        if (voltages[i] > threshold) {
            if (voltages[i] > voltages[i - 1] && voltages[i] > voltages[i + 1]) {
                this->peakCount++;
                timePoint.push_back(this->times[i]);
                peakIdx.push_back(i);
                signalPoint.push_back(voltages[i]);
                i += peakDelay;
            }
        }
}
void Patient::analyzeData(std::string fileName){
    readData(fileName);
    findPeakCount();
    for (int i = 1; i < timePoint.size(); ++i) {
        if (timePoint[i] - timePoint[i - 1] > 0.85)
            bradikardiIdx.push_back(i - 1);
        else if (timePoint[i] - timePoint[i - 1] < 0.3)
            tasikardiIdx.push_back(i - 1);
        else
            normalIdx.push_back(i - 1);
    }

    std::cout<<"Analyze has been finished correctly!\n";
}
void Patient::analyzeAndWriteForAll(){ 
    //Variables
    std::string fileName1;
    std::string fileName2;
    std::string fileName3;
    int firstDelay;
    int secondDelay;

    if(patientCount!=1){
        fileName1="Kisi-1-Tasikardi.txt";
        fileName2="Kisi-1-Normal.txt";
        fileName3="Kisi-1-Bradikardi.txt";
        firstDelay=0.08 / DIVIDED;
        secondDelay=0.26 / DIVIDED;
    }else{
        fileName1="Kisi-2-Tasikardi.txt";
        fileName2="Kisi-2-Normal.txt";
        fileName3="Kisi-2-Bradikardi.txt";
        firstDelay=0.09 / DIVIDED;
        secondDelay=0.53 / DIVIDED;
    }
    std::ofstream outputFile1(fileName1);
    std::ofstream outputFile2(fileName2);
    std::ofstream outputFile3(fileName3);

    if(!outputFile1.is_open()&&!outputFile2.is_open()&&!outputFile3.is_open()){
        std::cout<<"There is an error while opening one or all files open!"<<std::endl;
        return;
    }
    
    
    for (int i = this->peakIdx[tasikardiIdx[0]] - firstDelay; i < 120000; ++i)
        outputFile1 << this->times[i] << "\t" << this->voltages[i] << std::endl;
        
    for(int i = this->peakIdx[this->normalIdx[0]] - secondDelay; i < this->peakIdx[this->tasikardiIdx[0]] - firstDelay; ++i)
        outputFile2 << this->times[i] << "\t" << this->voltages[i] << std::endl;

    for (int i = 0; i < this->peakIdx[this->normalIdx[0]] - secondDelay; ++i)
        outputFile3 << this->times[i] << "\t" << this->voltages[i] << std::endl;
    

    patientCount++;

    outputFile1.close();
    outputFile2.close();
    outputFile3.close();
}

