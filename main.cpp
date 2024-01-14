#include <iostream>
#include "ECG.hpp"
using namespace std;


int main(){
    //Variables
        //For Patient Class
    string name;
    string dataFileName,outputFileName;

        //For Manager Class
    
    //Creating manager object
    Manager programManager("alldata2.txt","patient1.txt","patient2.txt","patient3.txt");
    programManager.readAndWriteData(); //Splitting the dataset


        //Patient operations 
    //Patient 1
    cout<<"Enter patient's name and surname: ";
    getline(cin,name);

    Patient patient1(name);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);

    patient1.readData(dataFileName);
    patient1.analyzeData();
    patient1.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    patient1.writeData(outputFileName);

    //----------------------------------------------------------------------------------------------------------------
    //Patient 2
    cout<<"Enter patient's name and surname: ";
    getline(cin,name);

    Patient patient2(name);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);

    patient2.readData(dataFileName);
    patient2.analyzeData();
    patient2.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    patient2.writeData(outputFileName);

    //----------------------------------------------------------------------------------------------------------------
    //Patient 3
    cout<<"Enter patient's name and surname: ";
    getline(cin,name);

    Patient patient3(name);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);

    patient3.readData(dataFileName);
    patient3.analyzeData();
    patient3.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    patient3.writeData(outputFileName);

    return 0;
}