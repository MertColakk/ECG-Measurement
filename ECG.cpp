#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ECG.hpp"

//Constructor
Patient::Patient(std::string name,std::string surname):name(name),surname(surname){
    this->voltages.clear();
    this->times.clear();
    this->result=" ";
    this->hearthRate=0.0;
}

//Other Functions
void Patient::readData(std::string fileName){
    //Variables
    std::ifstream dataFile(fileName);
    std::string timeString,voltageString;

    if(!dataFile.is_open()){
        std::cout<<"There is an error while reading the data file!"<<std::endl;
        return;
    }

    //Clearing vectors for better results
    this->times.clear();
    this->voltages.clear();

    std::string fileLine;
    std::getline(dataFile,fileLine); //For skipping the header line

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
void Patient::analyzeData(){
    //Variables
    const double voltageThreshold = 0.1;
    bool isAboveThreshold=false;
    double hearthRate=0.0;
    int peakCount=0;

    for(size_t i=0;i<this->voltages.size();i++){
        if(this->voltages.at(i)>voltageThreshold)
            isAboveThreshold=true;
        else{
            peakCount++;
            isAboveThreshold=false;
        }
    }

    if(peakCount>0){
        const double duration = this->times.back()-this->times.front();
        hearthRate = (peakCount / duration)*60.0;
    }

    this->hearthRate = hearthRate;

    std::cout<<"Patient's datas has been analyzed!"<<std::endl;

}

void Patient::findPatientResult(){
    if(this->hearthRate>100)
        this->result = "Tachycardia";
    else if(this->hearthRate>60)
        this->result = "Normal";
    else
        this->result = "Bradycardia";
    
    std::cout<<"Patient's result has been found!"<<std::endl;;
}
void Patient::writeData(std::string writeFileName){
    std::ofstream outputFile(writeFileName);

    if(!outputFile.is_open()){
        std::cout<<"There is an error while writing the data file!"<<std::endl;
        return;
    }

    outputFile<<this->name<<" "<<this->surname<<"'s status: "<<this->result<<std::endl;
    std::cout<<"Patient's result has been wrote correctly."<<std::endl;

}