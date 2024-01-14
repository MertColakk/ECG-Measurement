#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ECG.hpp"

        //Patient Class Operations
//Constructor
Patient::Patient(std::string nameSurname):nameSurname(nameSurname){
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
void Patient::analyzeData(){
    //Variables
    double hearthRate=0.0;
    int peakCount=0;

    const int duration = this->times.back()-this->times.front();

    for (size_t i = 1; i < this->voltages.size() - 1; i++) 
            if (this->voltages[i] > this->voltages[i - 1] && this->voltages[i] > this->voltages[i + 1]) 
                peakCount++;

    this->hearthRate = (peakCount/duration)*12.0;
    std::cout<<"Patient's datas has been analyzed!"<<std::endl;
    this->findPatientResult();

}

void Patient::findPatientResult(){
    if(this->hearthRate>100)
        this->result = "Tachycardia";
    else if(this->hearthRate>=60 && this->hearthRate<=100)
        this->result = "Normal";
    else if(this->hearthRate<=60)
        this->result = "Bradycardia";
    
    std::cout<<"Patient's result has been found!"<<std::endl;;
}
void Patient::writeData(std::string writeFileName){
    std::ofstream outputFile(writeFileName);

    if(!outputFile.is_open()){
        std::cout<<"There is an error while writing the data file!"<<std::endl;
        return;
    }

    outputFile<<this->nameSurname<<"'s status: "<<this->result<<std::endl;
    std::cout<<"Patient's result has been wrote correctly."<<std::endl;

}

        //Manager Class Operation
    //Constructor
    Manager::Manager(std::string readFileName,std::string writeFilePatient1Name,std::string writeFilePatient2Name,std::string writeFilePatient3Name){
        this->readFileName = readFileName;
        this->writeFilePatient1Name = writeFilePatient1Name;
        this->writeFilePatient2Name = writeFilePatient2Name;
        this->writeFilePatient3Name = writeFilePatient3Name;
    }

    //Other Function
    void Manager::readAndWriteData(){
    //Variables
    std::ifstream readFile(this->readFileName); 
    std::ofstream writeFilePatient1(this->writeFilePatient1Name); 
    std::ofstream writeFilePatient2(this->writeFilePatient2Name); 
    std::ofstream writeFilePatient3(this->writeFilePatient3Name); 
    std::string timeString,voltageString;
    std::string fileLine;

    if(!readFile.is_open()){
        std::cout<<"There is an error while reading the data file!"<<std::endl;
        return;
    }

    if(!writeFilePatient1.is_open()||!writeFilePatient2.is_open()||!writeFilePatient3.is_open()){
        std::cout<<"There is an error while writing the data file!"<<std::endl;
        return;
    }
    
    std::getline(readFile,fileLine); //For skipping the header line

    while(std::getline(readFile,fileLine)){
        std::istringstream lineStream(fileLine);

        if(!(lineStream>>timeString>>voltageString)){
            std::cout<<"Error while taking the lines from file!"<<std::endl;
            return;
        }
        if(std::stod(timeString)>=0.0 && std::stod(timeString)<=5.0)
            writeFilePatient1<<timeString<<"\t"<<voltageString<<std::endl;
        if(std::stod(timeString)>5.0 && std::stod(timeString)<=10.0)
            writeFilePatient2<<timeString<<"\t"<<voltageString<<std::endl;
        if(std::stod(timeString)>10.0 && std::stod(timeString)<=15.0)
            writeFilePatient3<<timeString<<"\t"<<voltageString<<std::endl; 
    }
    //File Closing
    readFile.close();
    writeFilePatient1.close();
    writeFilePatient2.close();
    writeFilePatient3.close();   
}