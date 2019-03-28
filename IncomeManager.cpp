#include <iostream>
#include <windows.h>
#include "IncomeManager.h"

using namespace std;

void IncomeManager::addIncome(){
    Income income=enterNewIncomeData();

    incomes.push_back(income);
    incomeFile.saveIncomeToFile(income);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"\n Your income has been saved.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system ("pause");
}

Income IncomeManager::enterNewIncomeData(){
    Income income;
    int transactionDate;
    string description;
    float incomeAmount;
    income.setIdIncome(setNewIncomeId());
    income.setIdUser(LOGGED_USER_ID);
    cout<<"Enter transaction date (YYYY-MM-DD): ";
    cin>>transactionDate; income.setTransactionDate(transactionDate);
    cout<<"Enter short transaction desription: ";
    cin>>description; income.setDescription(description);
    cout<<"Enter amount: ";
    cin>>incomeAmount; income.setIncomeAmount(incomeAmount);
    return income;
}

int IncomeManager::setNewIncomeId(){
    if(incomes.empty()==true) return 1;
    else return incomes.back().getIdIncome()+1;
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
