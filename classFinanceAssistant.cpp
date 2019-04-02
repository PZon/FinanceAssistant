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
        expenseManager=new ExpenseManager(EXPENSES_FILE_NAME, userManager.getIdLoggedUser());
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

void clFinanceAssistant::addExpense(){
    expenseManager->addExpense();
}

void clFinanceAssistant::statementCurrentMonth(){
    int startDate, endDate;
    startDate=SupportiveMethods::getDate('C');
    endDate=startDate+30;

    displayStatement(startDate,endDate);
};

void clFinanceAssistant::statementPreviousMonth(){
    int startDate, endDate;
    startDate=SupportiveMethods::getDate('P');
    endDate=startDate+30;

    displayStatement(startDate,endDate);
};

void clFinanceAssistant::statementSpecificPeriod(){
    int startDate, endDate;


    displayStatement(startDate,endDate);
};

void clFinanceAssistant::displayStatement(int startD, int endD){
    float incomes, expenses, sum;
    incomes=incomeManager->displayIncome(startD,endD);
    expenses=expenseManager->displayExpense(startD,endD);
    sum=incomes-expenses;
    system("cls");
    cout<<"Statement for period from "<<SupportiveMethods::addDashToDate(startD)<<" to "<<SupportiveMethods::addDashToDate(endD)<<endl;
    incomeManager->displayIncome(startD,endD);
    expenseManager->displayExpense(startD,endD);

    if(sum>0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"\n\nTOTAL: "<<setprecision(2)<<fixed<<sum<<" euro"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"\n\nTOTAL: "<<setprecision(2)<<fixed<<sum<<" euro"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
    system("pause");
}
