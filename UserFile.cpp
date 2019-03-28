#include <iostream>
#include "UserFile.h"

using namespace std;
void UsersFile::saveUserToFile(User user){
    CMarkup xml;
    fstream xmlFile;
    xmlFile.open(USERS_FILE_NAME.c_str(), ios::app);
    xml.Load(USERS_FILE_NAME.c_str());

    if(xmlFile.good()==true){
        if(ifFileEmpty(xmlFile)==true){
            xml.AddElem("Users");
            xml.IntoElem();
            xml.Save(USERS_FILE_NAME.c_str());
        }
        xml.FindElem();
        xml.IntoElem();

        xml.AddElem("User");
        xml.IntoElem();

        xml.AddElem("id",user.getId());
        xml.AddElem("name",user.getName());
        xml.AddElem("surname",user.getSurname());
        xml.AddElem("nick",user.getNick());
        xml.AddElem("password",user.getPassword());

        xml.Save(USERS_FILE_NAME.c_str());
        xmlFile.close();
    }
}

bool UsersFile::ifFileEmpty(fstream &xmlFile){
    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0) return true;
    else return false;
}

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

void UsersFile::updateUserPassword(int id, string password){
    CMarkup xml;
    xml.Load(USERS_FILE_NAME.c_str());

    xml.ResetPos();
    xml.FindElem();//users
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("id");
        int idXML = atoi( MCD_2PCSZ(xml.GetData()) );
        if (id == idXML){
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password",password);
        }
        xml.OutOfElem();
    }
    xml.Save(USERS_FILE_NAME.c_str());
}

