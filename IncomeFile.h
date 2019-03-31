#ifndef INCOMEFILE_H
#define INCOMEFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Markup.h"
#include "Income.h"
#include "SupportiveMethods.h"

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
    vector<Income>uploadIncomesFromFile(int loggedUserId);
    int setLastIncomeId();
};

#endif
