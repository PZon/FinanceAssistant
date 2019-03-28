#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

void UserManager::userRegistration(){
    User user=enterNewUserData();

    users.push_back(user);
    usersFile.saveUserToFile(user);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"\n Your account has been created successfully.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system ("pause");
}

User UserManager::enterNewUserData(){
    User user;
    string name, surname, nick, password;
    user.setId(setNewUserId());
    do{
        cout<<"Enter personal Nick name: ";
        cin>>nick;
        transform(nick.begin(), nick.end(),nick.begin(),::toupper);
        user.setNick(nick);
    }while(verifyNick(user.getNick())==true);

    cout<<"Enter name: "; cin>>name; user.setName(name);
    cout<<"Enter surname: "; cin>>surname; user.setSurname(surname);
    cout<<"Enter password: "; cin>>password; user.setPassword(password);
    return user;
}


bool UserManager::verifyNick(string nick){
    for(int i=0; i<users.size(); i++){
        if(users[i].getNick()==nick){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\nSorry but user with similar Nick is already registered.\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            return true;
        }
    }
    return false;
}

int UserManager::setNewUserId(){
    if(users.empty()==true) return 1;
    else return users.back().getId()+1;
}

void UserManager::loginForm(){
    User user;
    string nick="", password="";

    cout<<"\nEnter Nick / Login: "; nick=SupportiveMethods::getTxtLine();
    transform(nick.begin(), nick.end(),nick.begin(),::toupper);
    for(int i=0; i<users.size(); i++){
        if(nick==users[i].getNick()){
          for(int nr=1; nr<=3; nr++){
            cout<<nr<<" Attempt. Enter password: ";
            password=SupportiveMethods::getTxtLine();
            if(password==users[i].getPassword()){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"\nYou are successfully logged in."<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                loggedUserId=users[i].getId();
                system("pause");
                return;
            }
          }
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
          cout<<"\nUnfortunately you have entered 3 times wrong password."<<endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          system("pause");
          return;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"\nSorry but user with nick: "<<nick<<" is not registered in our system"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("pause");
    return;
}

int UserManager::getIdLoggedUser(){
    return loggedUserId;
}

bool UserManager::ifUserLoggedIn(){
    if(loggedUserId>0) return true;
    else return false;
}

void UserManager::userLogout(){
    cout<<"Successfully log out. "<<endl;
    loggedUserId=0;
    system("pause");
}

void UserManager::resetPassword(){
    string newPassword;
    cout<<"Please enter new password: "; cin>>newPassword;
    for(int i=0; i<users.size(); i++){
        if(users[i].getId()==loggedUserId){
            users[i].setPassword(newPassword);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"\nYour password has been changed"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            system("pause");
        }
    }
    usersFile.updateUserPassword(loggedUserId, newPassword);
}

/*********************************************/
void UserManager::wypiszUzytkownikow(){
     for(int i=0; i<users.size(); i++){
        cout<<users[i].getId()<<"|"<<users[i].getName()
        <<"|"<<users[i].getSurname()<<"|"<<users[i].getNick()<<"|"<<users[i].getPassword()<<endl;
    }
    system("pause");
}
