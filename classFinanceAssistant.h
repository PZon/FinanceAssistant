#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class clFinanceAssistant{
    UserManager userManager;
    IncomeManager *incomeManager;

    const string INCOMES_FILE_NAME;

public:
    clFinanceAssistant(string usersFileName, string incomesFileName):userManager(usersFileName),
    INCOMES_FILE_NAME(incomesFileName){
        incomeManager=NULL;
    };
    ~clFinanceAssistant(){
        delete incomeManager;
        incomeManager=NULL;
    }

    void userRegistration();
    void loginForm();
    void userLogout();
    bool ifUserLoggedIn();
    char mainMenu();
    char userMenu();
    void resetPassword();
    void addIncome();

    /****************************************/
    void wypiszUzytkownikow();
    void wypiszIncome();


};
