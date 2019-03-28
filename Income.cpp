#include <iostream>
#include "Income.h"

using namespace std;

void Income::setIdIncome(int idIncome){
    this->idIncome=idIncome;
}

void Income::setIdUser(int idUser){
    this->idUser=idUser;
}

void Income::setTransactionDate(int transactionDate){
    this->transactionDate=transactionDate;
}

void Income::setDescription(string description){
    this->description=description;
}

void Income::setIncomeAmount(float incomeAmount){
    this->incomeAmount=incomeAmount;
}

int Income::getIdIncome(){
    return idIncome;
}
int Income::getIdUser(){
    return idUser;
}

int Income::getTransactionDate(){
    return transactionDate;
}

string Income::getDescription(){
  return description;
}

float Income::getIncomeAmount(){
    return incomeAmount;
}
