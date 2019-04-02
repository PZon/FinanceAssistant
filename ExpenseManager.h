#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H
#include <iostream>
#include <vector>
#include "Expense.h"
#include "ExpenseFile.h"
#include "SupportiveMethods.h"

using namespace std;
class ExpenseManager{
    const int LOGGED_USER_ID;
    vector<Expense>expenses;
    ExpenseFile expenseFile;

public:
    ExpenseManager(string expensesFileName, int loggedUserId):expenseFile(expensesFileName),
        LOGGED_USER_ID(loggedUserId){
        expenses=expenseFile.uploadExpensesFromFile(LOGGED_USER_ID);
    }

    void addExpense();
    Expense enterNewExpenseData();
    float displayExpense(int startD, int endD);
};

#endif
