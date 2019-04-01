#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;
class Expense{
    int idExpense,idUser, transactionDate;
    string description;
    float expenseAmount;

public:
    void setIdExpense(int idExpense);
    void setIdUser(int idUser);
    void setTransactionDate(int transactionDate);
    void setDescription(string description);
    void setExpenseAmount(float expenseAmount);

    int getIdExpense();
    int getIdUser();
    int getTransactionDate();
    string getDescription();
    float getExpenseAmount();

};

#endif
