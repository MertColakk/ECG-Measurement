#include <iostream>
#include "ECG.hpp"
#include "Utility.hpp"
using namespace std;


int main(){
    //Patient 1
    Patient patient1;

    patient1.analyzeData("Person1.txt");

    patient1.analyzeAndWriteForAll();

    //----------------------------------------------------------------------------------------------------------------

    //Patient 2
    Patient patient2;

    patient2.analyzeData("Person2.txt");

    patient2.analyzeAndWriteForAll();

    writeForAll();

    return 0;
}
/*
****************************                                                   ****************************

                                Written By Mustafa Mert ÇOLAK and Ege ÇELİK    
                                                 22298506          22295230

****************************                                                   ****************************
*/