#include <iostream>
#include "UserManager.h"

using namespace std;

class clFinanceAssistant{
    UserManager userManager;

public:
    clFinanceAssistant(string usersFileName):userManager(usersFileName){};

    void userRegistration();
    void loginForm();
    void userLogout();
    bool ifUserLoggedIn();
    char mainMenu();
    char userMenu();
    void resetPassword();

    /****************************************/
    void wypiszUzytkownikow();


};
