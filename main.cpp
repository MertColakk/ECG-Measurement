#include <iostream>
#include "ECG.hpp"
using namespace std;


int main(){
    //Variables
    Patient patient1;
    string dataFileName,outputFileName;

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




    return 0;
}