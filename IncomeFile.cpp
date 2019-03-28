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
        xml.AddElem("amount",income.getIncomeAmount());

        xml.Save(INCOMES_FILE_NAME.c_str());
        xmlFile.close();
    }
}

/*
vector<User>UsersFile::uploadUsersFromFile(){
    CMarkup xml;
    fstream xmlFile;
    User user;
    vector<User>users;

    xmlFile.open(USERS_FILE_NAME.c_str(), ios::in);
    xml.Load(USERS_FILE_NAME.c_str());
    if(xmlFile.good()==true){
        xml.ResetPos();
        xml.FindElem();//users
        xml.IntoElem();

        while (xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("id");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("name");
            user.setName(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("surname");
            user.setSurname(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("nick");
            user.setNick(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("password");
            user.setPassword(xml.GetData());
            xml.ResetMainPos();

            users.push_back(user);
            xml.OutOfElem();
        }

        xmlFile.close();
    }
    return users;
}
*/
