#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;
class Income{
    int idIncome,idUser, transactionDate;
    string description;
    float incomeAmount;

public:
    void setIdIncome(int idIncome);
    void setIdUser(int idUser);
    void setTransactionDate(int transactionDate);
    void setDescription(string description);
    void setIncomeAmount(float incomeAmount);

    int getIdIncome();
    int getIdUser();
    int getTransactionDate();
    string getDescription();
    float getIncomeAmount();

};

#endif
