#include <iostream>

class Patient{
private:
    std::string name,surname;
    double hearthRate;
    std::string result;
    std::vector<double> times;
    std::vector<double> voltages;   
public:   
    //Constructor
    Patient(std::string name,std::string surname);

    //Other Functions
    void readData(std::string fileName);
    void analyzeData();
    void findPatientResult();
    void writeData(std::string writeFileName);
};  