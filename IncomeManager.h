#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomeFile.h"
#include "SupportiveMethods.h"

using namespace std;
class IncomeManager{
    const int LOGGED_USER_ID;
    vector<Income>incomes;
    IncomeFile incomeFile;

public:
    IncomeManager(string incomesFileName, int loggedUserId):incomeFile(incomesFileName),
    LOGGED_USER_ID(loggedUserId){
     incomes=incomeFile.uploadIncomesFromFile(LOGGED_USER_ID);
    }

    void addIncome();
    Income enterNewIncomeData();
    float displayIncome(int startD, int endD);
};

#endif
