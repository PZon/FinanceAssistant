#include <iostream>
#include <windows.h>
#include <iomanip>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SupportiveMethods.h"

using namespace std;

class clFinanceAssistant{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    clFinanceAssistant(string usersFileName, string incomesFileName, string expensesFileName )
    :userManager(usersFileName),INCOMES_FILE_NAME(incomesFileName),EXPENSES_FILE_NAME(expensesFileName)
    {
        incomeManager=NULL;
        expenseManager=NULL;
    };
    ~clFinanceAssistant(){
        delete incomeManager;
        delete expenseManager;
        incomeManager=NULL;
        expenseManager=NULL;
    }

    void userRegistration();
    void loginForm();
    void userLogout();
    bool ifUserLoggedIn();
    char mainMenu();
    char userMenu();
    void resetPassword();
    void addIncome();
    void addExpense();
    void statementCurrentMonth();
    void statementPreviousMonth();
    void statementSpecificPeriod();
    void displayStatement(int startD, int endD);
};
