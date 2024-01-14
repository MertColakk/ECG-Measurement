#include <iostream>
#include <vector>

class Patient{
private:
    int peakCount;
    int peakDelay = 0.1 / 0.000125;

    double hearthRate;

    std::string result;

    std::vector<double> times;
    std::vector<double> signalPoint; 
    std::vector<double> voltages;   
    std::vector<double> timePoint; 

    std::vector<int> peakIdx;
    std::vector<int> bradikardiIdx; 
    std::vector<int> tasikardiIdx;  
    std::vector<int> normalIdx;   
public:   
    //Constructor
    Patient();

    //Other Functions
    void readData(std::string fileName);
    void analyzeAndWriteForAll();

    void analyzeData(std::string fileName);
    void findPeakCount();
};  