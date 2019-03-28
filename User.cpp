#include <iostream>
#include "User.h"

using namespace std;

void User::setId(int id){
    this->id=id;
}

void User::setName(string name){
    this->name=name;
}

void User::setSurname(string surname){
    this->surname=surname;
}

void User::setNick(string nick){
    this->nick=nick;
}

void User::setPassword(string password){
    this->password=password;
}

int User::getId(){
    return id;
}
string User::getName(){
    return name;
}

string User::getSurname(){
    return surname;
}

string User::getNick(){
  return nick;
}

string User::getPassword(){
    return password;
}
