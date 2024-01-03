#include <iostream>
#include "ECG.hpp"
using namespace std;


int main(){
    //Variables
    string name,surname;
    string dataFileName,outputFileName;

    //Patient 1
    cout<<"Enter patient's name: ";
    cin>>name;

    cout<<"Enter patient's surname: ";
    cin>>surname;

    Patient patient1(name,surname);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);
    cin.ignore();

    patient1.readData(dataFileName);
    patient1.analyzeData();
    patient1.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    cin.ignore();
    patient1.writeData(outputFileName);

    //----------------------------------------------------------------------------------------------------------------
    //Patient 2
    cout<<"Enter patient's name: ";
    cin>>name;

    cout<<"Enter patient's surname: ";
    cin>>surname;

    Patient patient2(name,surname);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);
    cin.ignore();

    patient2.readData(dataFileName);
    patient2.analyzeData();
    patient2.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    cin.ignore();
    patient2.writeData(outputFileName);

    //----------------------------------------------------------------------------------------------------------------
    //Patient 3
    cout<<"Enter patient's name: ";
    cin>>name;

    cout<<"Enter patient's surname: ";
    cin>>surname;

    Patient patient3(name,surname);

    cout<<"Enter the data file name for read: ";
    getline(cin,dataFileName);
    cin.ignore();

    patient3.readData(dataFileName);
    patient3.analyzeData();
    patient3.findPatientResult();

    cout<<"Analyze has been finished correctly!\n"<<"Please enter a file name for writing the patient results: ";
    getline(cin,outputFileName);
    cin.ignore();
    patient3.writeData(outputFileName);

    return 0;
}