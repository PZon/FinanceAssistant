#include <iostream>
#include "IncomeFile.h"

using namespace std;

bool IncomeFile::ifFileEmpty(fstream &xmlFile){
    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0) return true;
    else return false;
}

void IncomeFile::saveIncomeToFile(Income income){
    CMarkup xml;
    fstream xmlFile;
    xmlFile.open(INCOMES_FILE_NAME.c_str(), ios::app);
    xml.Load(INCOMES_FILE_NAME.c_str());

    if(xmlFile.good()==true){
        if(ifFileEmpty(xmlFile)==true){
            xml.AddElem("Incomes");
            xml.IntoElem();
            xml.Save(INCOMES_FILE_NAME.c_str());
        }
        xml.FindElem();
        xml.IntoElem();

        xml.AddElem("Income");
        xml.IntoElem();

        xml.AddElem("idIncome",income.getIdIncome());
        xml.AddElem("idUser",income.getIdUser());
        xml.AddElem("date",income.getTransactionDate());
        xml.AddElem("description",income.getDescription());
        xml.AddElem("amount",SupportiveMethods::convertFloatToStr(income.getIncomeAmount()));

        xml.Save(INCOMES_FILE_NAME.c_str());
        xmlFile.close();
    }
    lastIncomeId++;
}


vector<Income>IncomeFile::uploadIncomesFromFile(int loggedUserId){
    CMarkup xml;
    fstream xmlFile;
    Income income;
    vector<Income>incomes;
    int tmpUserId;

    xmlFile.open(INCOMES_FILE_NAME.c_str(), ios::in);
    xml.Load(INCOMES_FILE_NAME.c_str());
    if(xmlFile.good()==true){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")){
            xml.IntoElem();
            xml.FindElem("idIncome");
            lastIncomeId=atoi(MCD_2PCSZ(xml.GetData()));
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("idUser");
            tmpUserId=atoi(MCD_2PCSZ(xml.GetData()));

           if(loggedUserId==tmpUserId){
                xml.ResetMainPos();
                xml.IntoElem();
                xml.FindElem("idIncome");
                //lastIncomeId=atoi(MCD_2PCSZ(xml.GetData()));
                //income.setIdIncome(atoi(MCD_2PCSZ(xml.GetData())));
                income.setIdIncome(lastIncomeId);
                xml.ResetMainPos();

                xml.FindElem("idUser");
                income.setIdUser(atoi(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                xml.FindElem("date");
                income.setTransactionDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                xml.FindElem("description");
                income.setDescription(xml.GetData());
                xml.ResetMainPos();

                xml.FindElem("amount");
                income.setIncomeAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.ResetMainPos();

                incomes.push_back(income);
            }//endif;
            xml.OutOfElem();
        }
        xmlFile.close();
    }
    return incomes;
}

int IncomeFile::setLastIncomeId(){
        return lastIncomeId+1;
}
