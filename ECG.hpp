#include <iostream>

class Patient{
private:
    std::string nameSurname;
    double hearthRate;
    std::string result;
    std::vector<double> times;
    std::vector<double> voltages;   
public:   
    //Constructor
    Patient(std::string nameSurname);

    //Other Functions
    void readData(std::string fileName);
    void analyzeData();
    void findPatientResult();
    void writeData(std::string writeFileName);
};  

class Manager{
private:
    std::string readFileName;
    std::string writeFilePatient1Name;
    std::string writeFilePatient2Name;
    std::string writeFilePatient3Name;
public:
    //Constructor
    Manager(std::string readFileName,std::string writeFilePatient1Name,std::string writeFilePatient2Name,std::string writeFilePatient3Name);

    //Other function
    void readAndWriteData();

};