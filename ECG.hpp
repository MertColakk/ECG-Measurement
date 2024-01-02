#include <iostream>

class Patient{
private:
    double hearthRate;
    std::string result;
    std::vector<double> times;
    std::vector<double> voltages;   
public:   
    //Constructor
    Patient();

    //Other Functions
    void readData(std::string fileName);
    void analyzeData();
    void findPatientResult();
    void writeData(std::string writeFileName);
};  