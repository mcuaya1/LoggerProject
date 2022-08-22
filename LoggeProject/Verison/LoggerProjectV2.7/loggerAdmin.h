#ifndef LOGGERADMIN_H
#define LOGGERADMIN_H
#include <string>
#include <vector>
#include "loggerUser.h"
#include "logHoursClass.h"

using namespace std;

class loggerAdmin{
  public:
    loggerAdmin(string adminName, string adminPass);

    void setAdminName(string);
    void setAdminPass(string);
    void setUserInfo(vector <logUser>);
    vector <logUser> passUserInfo();
    vector <string> passLabSections();

    string getAdminName();
    string getAdminPass();

    void viewUsers();
    void deleteUsers();
    void viewUserHours();
    void addUserHours();
    void deleteUserHours();
    void editUsers();

    void createLab();
    void deleteLab();
    void addLab();
    void editLab();
    void viewLabs();
  private:
    string adminName, adminPass;
    bool adminCheck;
    vector <string> labSections;
    vector <logUser> userINFO;
    
};

#endif