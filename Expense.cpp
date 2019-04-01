#include <iostream>
#include "Expense.h"

using namespace std;

void Expense::setIdExpense(int idExpense){
    this->idExpense=idExpense;
}

void Expense::setIdUser(int idUser){
    this->idUser=idUser;
}

void Expense::setTransactionDate(int transactionDate){
    this->transactionDate=transactionDate;
}

void Expense::setDescription(string description){
    this->description=description;
}

void Expense::setExpenseAmount(float expenseAmount){
    this->expenseAmount=expenseAmount;
}

int Expense::getIdExpense(){
    return idExpense;
}
int Expense::getIdUser(){
    return idUser;
}

int Expense::getTransactionDate(){
    return transactionDate;
}

string Expense::getDescription(){
  return description;
}

float Expense::getExpenseAmount(){
    return expenseAmount;
}
