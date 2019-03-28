#ifndef INCOMEFILE_H
#define INCOMEFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Markup.h"
#include "Income.h"

using namespace std;
class IncomeFile{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

    bool ifFileEmpty(fstream &xmlFile);
public:
    IncomeFile(string incomesFileName):INCOMES_FILE_NAME(incomesFileName){
        lastIncomeId=0;
    }
    void saveIncomeToFile(Income income);
   // vector<Income>uploadIncomesFromFile(Income income);
};

#endif
