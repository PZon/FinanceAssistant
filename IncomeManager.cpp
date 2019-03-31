#include <iostream>
#include <windows.h>
#include "IncomeManager.h"

using namespace std;

void IncomeManager::addIncome(){
    Income income=enterNewIncomeData();
    if(income.getDescription()==""){cout<<"\nError";system ("pause");
    }else{
        incomes.push_back(income);
        incomeFile.saveIncomeToFile(income);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"\n Your income has been saved.\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        system ("pause");
    }
}

Income IncomeManager::enterNewIncomeData(){
    Income income;
    char choice;
    int transactionDate;
    string strTransDate=SupportiveMethods::strCurrentDate('-');
    string description;
    float incomeAmount;
    bool dateVeryfication=false;

    income.setIdIncome(incomeFile.setLastIncomeId());
    income.setIdUser(LOGGED_USER_ID);
    cout<<"\nWhat is transaction date\n";
    cout<<"1. Current date: "<<strTransDate<<" "<<endl;
    cout<<"2. Preferred specific date.\n";
    cout<<"===========================================\n";
    cout<<"Your choice: ";
    choice = SupportiveMethods::verifyChar();
        switch(choice){
        case '1':
            strTransDate=SupportiveMethods::strCurrentDate('0');
            dateVeryfication=true;
            break;
        case '2':
            cout<<"Enter transaction date (YYYY-MM-DD): ";
            strTransDate=SupportiveMethods::getTxtLine();
            dateVeryfication=SupportiveMethods::verifyUserDate(strTransDate);
            break;
        }

        if(dateVeryfication==true){
            strTransDate=SupportiveMethods::removePauses(strTransDate);
            transactionDate=SupportiveMethods::convertStringToInt(strTransDate);
            income.setTransactionDate(transactionDate);
            cout<<"Enter short transaction description: ";
            description=SupportiveMethods::getTxtLine();
            income.setDescription(description);
            cout<<"Enter amount: ";
            cin>>incomeAmount; income.setIncomeAmount(incomeAmount);
            return income;
        }else cout<<"\nWrong date!!!";
}
/*********************************************/
void IncomeManager::wypiszIncome(){
    for(int i=0; i<incomes.size(); i++){
        cout<<incomes[i].getIdIncome()<<"|"<<incomes[i].getIdUser()
        <<"|"<<incomes[i].getTransactionDate()<<"|"<<incomes[i].getDescription()<<"|"
        <<incomes[i].getIncomeAmount()<<endl;
    }
    system("pause");
}
