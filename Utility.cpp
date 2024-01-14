#include <iostream>
#include <fstream>
#include <sstream>

void writeForAll(){
    
    //Variables
    std::ofstream outputFile1("Tasikardi-Kisi-1-2.txt");
    std::ofstream outputFile2("Normal-Kisi-1-2.txt");
    std::ofstream outputFile3("Bradikardi-Kisi-1-2.txt");

    std::ifstream inputFile1("Kisi-1-Tasikardi.txt");
    std::ifstream inputFile2("Kisi-1-Tasikardi.txt");
    std::ifstream inputFile3("Kisi-1-Normal.txt");
    std::ifstream inputFile4("Kisi-2-Normal.txt");
    std::ifstream inputFile5("Kisi-1-Bradikardi.txt");
    std::ifstream inputFile6("Kisi-2-Bradikardi.txt");

    double time,voltage;

    if(!outputFile1.is_open()&&!outputFile2.is_open()&&!outputFile3.is_open()){
        std::cout<<"There is an error while opening one or all files open!"<<std::endl;
        return;
    }

    if(!inputFile1.is_open()&&!inputFile2.is_open()&&!inputFile3.is_open()&&!inputFile4.is_open()&&!inputFile5.is_open()&&!inputFile6.is_open()){
        std::cout<<"There is an error while opening one or all files open!"<<std::endl;
        return;
    }
    
        //Write The Files
    //File 2
    while(inputFile1 >> time >> voltage) 
        outputFile1 << time << "\t    " << voltage << std::endl;
    
    outputFile1 << "******************************************" << std::endl;

    while(inputFile2 >> time >> voltage) 
        outputFile1 << time << "\t    " << voltage << std::endl;
    
    //File 2
    while(inputFile3 >> time >> voltage) 
        outputFile2 << time << "\t    " << voltage << std::endl;
    
    outputFile2 << "******************************************" << std::endl;

    while(inputFile4 >> time >> voltage) 
        outputFile2 << time << "\t    " << voltage << std::endl;
    
    //File 3
    while(inputFile5 >> time >> voltage) 
        outputFile3 << time << "\t    " << voltage << std::endl;
    
    outputFile3 << "******************************************" << std::endl;

    while(inputFile6 >> time >> voltage) 
        outputFile3 << time << "\t    " << voltage << std::endl;



    //Close the all files
    outputFile1.close();
    outputFile2.close();
    outputFile3.close();
    inputFile1.close();
    inputFile2.close();
    inputFile3.close();
    inputFile4.close();
    inputFile5.close();
    inputFile6.close();
}