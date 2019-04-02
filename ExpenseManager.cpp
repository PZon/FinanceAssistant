#include <iostream>
#include <windows.h>
#include "ExpenseManager.h"

using namespace std;

void ExpenseManager::addExpense(){
    Expense expense=enterNewExpenseData();
    if(expense.getDescription()==""){cout<<"\nError";system ("pause");
    }else{
        expenses.push_back(expense);
        expenseFile.saveExpenseToFile(expense);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"\n Your expense has been saved.\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        system ("pause");
    }
}

Expense ExpenseManager::enterNewExpenseData(){
    Expense expense;
    char choice;
    int transactionDate;
    string strTransDate="";
    string strAmount="";
    string description;
    float expenseAmount;
    bool dateVeryfication=false;
    bool amountVeryfication=false;

    expense.setIdExpense(expenseFile.setLastExpenseId());
    expense.setIdUser(LOGGED_USER_ID);
    cout<<"\nWhat is transaction date\n";
    cout<<"1. Current date: "<<SupportiveMethods::strCurrentDate('-')<<" "<<endl;
    cout<<"2. Preferred specific date.\n";
    cout<<"===========================================\n";
    cout<<"Your choice: ";
    choice = SupportiveMethods::verifyChar();
        switch(choice){
        case '1':
            strTransDate=SupportiveMethods::strCurrentDate('-');
            dateVeryfication=true;
            break;
        case '2':
                do{cout<<"Enter transaction date (YYYY-MM-DD): ";
                    strTransDate=SupportiveMethods::getTxtLine();
                    dateVeryfication=SupportiveMethods::verifyUserDate(strTransDate);
                    if(dateVeryfication==false){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                        cout<<"\nWrong date!!!\n";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        Sleep(1500);
                    }
                }while(dateVeryfication==false);
            break;
        }

            strTransDate=SupportiveMethods::removePauses(strTransDate);
            transactionDate=SupportiveMethods::convertStringToInt(strTransDate);
            expense.setTransactionDate(transactionDate);

           cout<<"Enter short transaction description: ";
           description=SupportiveMethods::getTxtLine();
           expense.setDescription(description);

        do{cout<<"Enter amount: ";
           cin>>strAmount;
            amountVeryfication=SupportiveMethods::verifyAmount(strAmount);
            strAmount=SupportiveMethods::swapCommaWithDot(strAmount);
            expenseAmount=atof(strAmount.c_str());
            expense.setExpenseAmount(expenseAmount);
                if(amountVeryfication==false){
                   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                   cout<<"\nIncorrect  amount!!!\n";
                   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                }
            }while(amountVeryfication==false);
        return expense;
}

float ExpenseManager::displayExpense(int startD, int endD){
    float sumExpenses=0.00;
    int intDate; string strDate;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"\tEXPENSES: \n";
    cout<<"Id |    Date    | Description | Amount "<<endl;
    cout<<"======================================="<<endl;
    for(int i=0; i<expenses.size(); i++){
        if((expenses[i].getTransactionDate()>=startD)&&(expenses[i].getTransactionDate()<=endD)){
            intDate=expenses[i].getTransactionDate();
            strDate=SupportiveMethods::addDashToDate(intDate);
            cout<<expenses[i].getIdExpense()<<"  | "<<strDate<<" | "
            <<expenses[i].getDescription()<<"  |   "<<expenses[i].getExpenseAmount()<<" euro"<<endl;
            sumExpenses+=expenses[i].getExpenseAmount();
       }
    }
    cout<<"======================================="<<endl;
    cout<<"Total Expenses: "<<sumExpenses<<" euro"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    return sumExpenses;
}
