#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Markup.h"
#include "Expense.h"
#include "SupportiveMethods.h"

using namespace std;
class ExpenseFile{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

    bool ifFileEmpty(fstream &xmlFile);
public:
    ExpenseFile(string expensesFileName):EXPENSES_FILE_NAME(expensesFileName){
        lastExpenseId=0;
    }
    void saveExpenseToFile(Expense expense);
    vector<Expense>uploadExpensesFromFile(int loggedUserId);
    int setLastExpenseId();
};

#endif
