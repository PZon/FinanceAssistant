#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Markup.h"
#include "User.h"

using namespace std;
class UsersFile{
    const string USERS_FILE_NAME;

    bool ifFileEmpty(fstream &xmlFile);
public:
    UsersFile(string usersFileName):USERS_FILE_NAME(usersFileName){};
    void saveUserToFile(User user);
    vector<User>uploadUsersFromFile();
    void updateUserPassword(int id, string password);
};

#endif // USERFILE_H

