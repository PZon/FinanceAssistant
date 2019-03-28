#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;
class User{
    int id;
    string name, surname, nick, password;

public:
    void setId(int id);
    void setName(string name);
    void setSurname(string surname);
    void setNick(string nick);
    void setPassword(string password);

    int getId();
    string getName();
    string getSurname();
    string getNick();
    string getPassword();

};

#endif
