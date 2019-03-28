#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "User.h"
#include "UserFile.h"
#include "SupportiveMethods.h"

using namespace std;

class UserManager{
    int loggedUserId;
    vector<User>users;
    UsersFile usersFile;

    int setNewUserId();
    bool verifyNick(string nick);

public:
    UserManager(string usersFileName):usersFile(usersFileName){
        loggedUserId=0;
        users=usersFile.uploadUsersFromFile();
    }
    void userRegistration();
    User enterNewUserData();
    void loginForm();
    int getIdLoggedUser();
    bool ifUserLoggedIn();
    void userLogout();
    void resetPassword();

    /************************/
    void wypiszUzytkownikow();

};

#endif
