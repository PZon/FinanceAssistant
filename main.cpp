#include <iostream>
#include "FinanceAssistant.h"

using namespace std;

int main()
{
    char choice;
    clFinanceAssistant financeAssistant("Users.xml", "Incomes.xml","Expenses.xml");
    financeAssistant.ifUserLoggedIn();
    while(true){
        if(financeAssistant.ifUserLoggedIn()==false){
            choice=financeAssistant.mainMenu();

            switch(choice){
                case '1':
                   financeAssistant.userRegistration();
                   break;
                case '2':
                    financeAssistant.loginForm();
                    break;
                case '0':
                    exit(0);
                    break;
            }
        }else{
            choice=financeAssistant.userMenu();
            switch (choice){
            case '1':
                financeAssistant.addIncome();
                break;
            case '2':
                financeAssistant.addExpense();
                break;
            case '3':
                financeAssistant.statementCurrentMonth();
                break;
            case '4':
                financeAssistant.statementPreviousMonth();
                break;
            case '5':
                financeAssistant.statementSpecificPeriod();
                break;
            case '6':
                financeAssistant.resetPassword();
                break;
            case '0':
                financeAssistant.userLogout();
                break;

            }
        }
    }
    return 0;
}
