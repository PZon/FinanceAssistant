#include <iostream>
#include "ExpenseFile.h"

using namespace std;

bool ExpenseFile::ifFileEmpty(fstream &xmlFile){
    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0) return true;
    else return false;
}

void ExpenseFile::saveExpenseToFile(Expense expense){
    CMarkup xml;
    fstream xmlFile;
    xmlFile.open(EXPENSES_FILE_NAME.c_str(), ios::app);
    xml.Load(EXPENSES_FILE_NAME.c_str());

    if(xmlFile.good()==true){
        if(ifFileEmpty(xmlFile)==true){
            xml.AddElem("Expenses");
            xml.IntoElem();
            xml.Save(EXPENSES_FILE_NAME.c_str());
        }
        xml.FindElem();
        xml.IntoElem();

        xml.AddElem("Expense");
        xml.IntoElem();

        xml.AddElem("idExpense",expense.getIdExpense());
        xml.AddElem("idUser",expense.getIdUser());
        xml.AddElem("date",expense.getTransactionDate());
        xml.AddElem("description",expense.getDescription());
        xml.AddElem("amount",SupportiveMethods::convertFloatToStr(expense.getExpenseAmount()));

        xml.Save(EXPENSES_FILE_NAME.c_str());
        xmlFile.close();
    }
    lastExpenseId++;
}


vector<Expense>ExpenseFile::uploadExpensesFromFile(int loggedUserId){
    CMarkup xml;
    fstream xmlFile;
    Expense expense;
    vector<Expense>expenses;
    int tmpUserId;

    xmlFile.open(EXPENSES_FILE_NAME.c_str(), ios::in);
    xml.Load(EXPENSES_FILE_NAME.c_str());
    if(xmlFile.good()==true){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Expense")){
            xml.IntoElem();
            xml.FindElem("idExpense");
            lastExpenseId=atoi(MCD_2PCSZ(xml.GetData()));
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("idUser");
            tmpUserId=atoi(MCD_2PCSZ(xml.GetData()));

            if(loggedUserId==tmpUserId){
                xml.ResetMainPos();
                xml.IntoElem();
                xml.FindElem("idExpense");
                //lastExpenseId=atoi(MCD_2PCSZ(xml.GetData()));
               // expense.setIdExpense(atoi(MCD_2PCSZ(xml.GetData())));
                expense.setIdExpense(lastExpenseId);
                xml.ResetMainPos();

                xml.FindElem("idUser");
                expense.setIdUser(atoi(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                xml.FindElem("date");
                expense.setTransactionDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                xml.FindElem("description");
                expense.setDescription(xml.GetData());
                xml.ResetMainPos();

                xml.FindElem("amount");
                expense.setExpenseAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
        xmlFile.close();
    }
    return expenses;
}

int ExpenseFile::setLastExpenseId(){
        return lastExpenseId+1;
}
