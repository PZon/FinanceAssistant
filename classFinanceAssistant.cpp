#include <iostream>
#include "classFinanceAssistant.h"

using namespace std;

void clFinanceAssistant::userRegistration(){
    userManager.userRegistration();
}

void clFinanceAssistant::loginForm(){
    userManager.loginForm();
    if(userManager.ifUserLoggedIn()){
        incomeManager=new IncomeManager(INCOMES_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void clFinanceAssistant::userLogout(){
    userManager.userLogout();
}
bool clFinanceAssistant::ifUserLoggedIn(){
    userManager.ifUserLoggedIn();
}

char clFinanceAssistant::mainMenu(){
    char choice;
    system("cls");

    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register form" << endl;
    cout << "2. Log In" << endl;
    cout << "0. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportiveMethods::verifyChar();

    return choice;
}

char clFinanceAssistant::userMenu(){
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month statement" << endl;
    cout << "4. Previous month statement" << endl;
    cout << "5. Specific period statement" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "0. Log Out" << endl;
    cout << "9. wyswietl test" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportiveMethods::verifyChar();

    return choice;
}

void clFinanceAssistant::resetPassword(){
    userManager.resetPassword();
}

void clFinanceAssistant::addIncome(){
    incomeManager->addIncome();
}
/*******************************************/
void clFinanceAssistant::wypiszUzytkownikow(){
    userManager.wypiszUzytkownikow();
}
void clFinanceAssistant::wypiszIncome(){
    incomeManager->wypiszIncome();
}
