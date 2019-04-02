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
    string strTransDate="";
    string strAmount="";
    string description;
    float incomeAmount;
    bool dateVeryfication=false;
    bool amountVeryfication=false;

    income.setIdIncome(incomeFile.setLastIncomeId());
    income.setIdUser(LOGGED_USER_ID);
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
            income.setTransactionDate(transactionDate);

           cout<<"Enter short transaction description: ";
           description=SupportiveMethods::getTxtLine();
           income.setDescription(description);

        do{cout<<"Enter amount: ";
           cin>>strAmount;
            amountVeryfication=SupportiveMethods::verifyAmount(strAmount);
            strAmount=SupportiveMethods::swapCommaWithDot(strAmount);
            incomeAmount=atof(strAmount.c_str());
            income.setIncomeAmount(incomeAmount);
                if(amountVeryfication==false){
                   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                   cout<<"\nIncorrect  amount!!!\n";
                   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                }
            }while(amountVeryfication==false);
        return income;
}

int IncomeManager::displayIncome(int startD, int endD){
    float sumIncomes=0;
    int intDate; string strDate;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout<<"\n\tINCOMES: \n";
    cout<<"Id |    Date    | Description | Amount "<<endl;
    cout<<"======================================="<<endl;
    for(int i=0; i<incomes.size(); i++){
        if((incomes[i].getTransactionDate()>=startD)&&(incomes[i].getTransactionDate()<=endD)){
            intDate=incomes[i].getTransactionDate();
            strDate=SupportiveMethods::addDashToDate(intDate);
            cout<<incomes[i].getIdIncome()<<"  | "<<strDate
            <<" | "<<incomes[i].getDescription()<<"  |   "<<incomes[i].getIncomeAmount()<<"euro"<<endl;
            sumIncomes+=incomes[i].getIncomeAmount();
       }
    }
    cout<<"======================================="<<endl;
    cout<<"Total Income: "<<sumIncomes<<"euro\n"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    return sumIncomes;
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
