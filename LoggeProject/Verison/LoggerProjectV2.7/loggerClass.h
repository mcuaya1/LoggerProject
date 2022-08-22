#ifndef LOGGERCLASS_H
#define LOGGERCLASS_H
#include <string>
#include "loggerUser.h"
#include "logHoursClass.h"
#include "loggerAdmin.h"

using namespace std;

class loggerClass{
  public:
    loggerClass();

    void createAccount();
    void menu();
    void adminMenu(loggerAdmin);
    bool checkUser(logUser);
    bool checkAdmin(loggerAdmin);
    
    void storeUserInfo(logUser);
    void storeAdminInfo(loggerAdmin);
    void storeHoursIN(logHoursClass);
    void storeHoursOUT(logHoursClass);


    logUser currUser(logUser);
    loggerAdmin currAdmin(loggerAdmin);

    vector <string> passLabs();
    vector <logUser> passUsers();

    void setUserInfo(vector <logUser>);
    void setLabs(vector <string>);
    vector <string> getCurrLabs();
  private:
    vector <string> labSections;
    vector <logUser> userINFO;
    vector <loggerAdmin> adminINFO;
    
};

#endif /* LOGGERUSER_H */