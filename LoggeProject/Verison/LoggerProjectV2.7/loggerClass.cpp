#include "loggerClass.h"
#include "loggerUser.h"
#include "loggerAdmin.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

loggerClass::loggerClass(){
  cout << "Welcome..." << endl;
};

void loggerClass::createAccount(){
  string userName;
  string userPassword;
  int studentID;
  cout << "Enter a username: " << endl;
  cin >> userName;
  cout << "Enter a password: " << endl;
  cin >> userPassword;
  cout << "Etner your student ID " << endl;
  cin >> studentID;

  logUser newUser(userName,userPassword, studentID);
  storeUserInfo(newUser);
}

bool loggerClass::checkUser(logUser tempUser){
  bool flagCheck = false;
  for(int i = 0; i < userINFO.size(); i++){
    if(tempUser.getUsername() == userINFO[i].getUsername() && tempUser.getUserPassword() == userINFO[i].getUserPassword()){
        flagCheck = true;
    } 
  }
  return flagCheck;

};

bool loggerClass::checkAdmin(loggerAdmin tempAdmin){
  bool flagCheck = false;
  for(int i = 0; i < adminINFO.size(); i++){
    if(tempAdmin.getAdminName() == adminINFO[i].getAdminName() && adminINFO[i].getAdminPass() == tempAdmin.getAdminPass()){
      flagCheck = true;
    }
  }
  return flagCheck;
};

logUser loggerClass::currUser(logUser currUser){
  logUser tempUser("TEMP", "TEMP", 12345678);
  for(int i = 0; i < userINFO.size(); i++){
    if(currUser.getUsername() == userINFO[i].getUsername() && currUser.getUserPassword() == userINFO[i].getUserPassword()){
      tempUser.setUsername(userINFO[i].getUsername());
      tempUser.setUserPassword(userINFO[i].getUserPassword());
      tempUser.setStudentID(userINFO[i].getStudentID());
    }
  }
  return tempUser;
};

loggerAdmin loggerClass::currAdmin(loggerAdmin currAdmin){
  loggerAdmin tempAdmin("TEMP","TEMP");
    for(int i = 0; i < adminINFO.size(); i++){
    if(currAdmin.getAdminName() == adminINFO[i].getAdminName() && currAdmin.getAdminPass() == adminINFO[i].getAdminPass()){
      tempAdmin.setAdminName(adminINFO[i].getAdminName());
      tempAdmin.setAdminPass(adminINFO[i].getAdminPass());
    }
  }
  return tempAdmin;
};

void loggerClass::adminMenu(loggerAdmin admin){
  int yesOrNo;
  int signInOrNot;
  int flagCheck;
  int flagCheck1;
  int inOrOutCheck;
  cout << "Welcome " << admin.getAdminName() << endl;
  do{
    cout << "1)View current users... " << endl;
    cout << "2)View user hours..." << endl;
    cout << "3)Create lab Sections " << endl;
    cout << "4)Sign out..." << endl;
    cin >> flagCheck;

    if(flagCheck == 1){

        admin.viewUsers();
        do{
          cout << "1)Delete users..." << endl;
          cout << "2)Edit users..." << endl;
          cout << "3)Return..." << endl;
          cin >> flagCheck1;
          if(flagCheck1 == 1){
            admin.deleteUsers();
            userINFO = admin.passUserInfo();
          }
          else if(flagCheck1 == 2){
            admin.editUsers();
            userINFO = admin.passUserInfo();
          }
        }while(flagCheck1 != 3);
    }
    else if(flagCheck == 2){
      admin.viewUserHours();
      do{
          cout << "1)Delete user's hours..." << endl;
          cout << "2)Add onto user's hours..." << endl;
          cout << "3)Return..." << endl;
          cin >> flagCheck;
          if(flagCheck == 1){
            admin.deleteUserHours();
            userINFO = admin.passUserInfo();
          }
          else if(flagCheck == 2){
            admin.addUserHours();
            userINFO = admin.passUserInfo();
          }
          else if(flagCheck == 3){
            break;
          }
        }while(flagCheck != 3);
    }
    else if(flagCheck == 3){
      do{
          cout << "1)Delete lab sections..." << endl;
          cout << "2)Add lab sections..." << endl;
          cout << "3)Return..." << endl;
          cin >> flagCheck;
          if(flagCheck == 1){
            admin.deleteLab();
            labSections = admin.passLabSections();
          }
          else if(flagCheck == 2){
            admin.createLab();
            labSections = admin.passLabSections();
          }
          else if(flagCheck == 3){
            break;
          }
        }while(flagCheck != 3);
    }
  }while(flagCheck != 4);
};

void loggerClass::menu(){
  logUser currentUser("HOLDER", "HOLDER", 1234678);
  loggerAdmin currentAdmin("HOLDER", "HOLDER");
  string userName;
  string userPassword;
  string labSection;

  int month;
  int day;
  int year;
  int hour;
  int mintue;
  string ampm;
   
  char yesOrNo;
  char signInOrNot;
  int flagCheck;
  int inOrOutCheck;

  do{
    cout << "Would you like to sign in or exit the program..." << endl;
    cout << "Type 'Y ' to sign in or type 'X' to exit the program..." << endl;
    cin >> signInOrNot;
    if(signInOrNot == 'Y'){
      cout << "Username: " << endl;
      cin >> userName;
      cout << "Password: " << endl;
      cin >> userPassword;
    logUser tempUser(userName, userPassword, 1234678);
    loggerAdmin tempAdmin(userName, userPassword);
    if(checkUser(tempUser) == true){
      currentUser = currUser(tempUser);
      cout << "Account found..." << endl;
      cout << "Welcome " << userName << endl;
      currentUser.setCurrLabs(getCurrLabs());
      do{
          cout << "What would you like to do? " << endl;
          cout << "1) Choose a lab section and log hours in or out... " << endl;
          cout << "2) Sign out and exit the program..." << endl;
          cout << "3) View hours logged for a lab section..." << endl;
          cin >> flagCheck;
          if( flagCheck == 1){
            currentUser.viewLabs();
            cout << "Please enter the Lab section you would like to log hours... " << endl;
            cin >> labSection;
            cout << "Are you logging hours in or out? " << endl;
            cout << "Type 1 to log hours in or type 2 to log hours out " << endl;
            cin >> inOrOutCheck;
            if(inOrOutCheck == 1){
              cout << "Please enter the following MM/DD/YYYY " << endl;
              scanf("%d/%d/%d", &month, &day, &year);
              cout << "Please enter the following HH:MM" << endl;
              scanf("%d:%d", &hour,&mintue);
              cout << "AM or PM" << endl;
              cin >> ampm;
                if(ampm == "AM"){
                    ampm = "AM";
                }
                else if(ampm == "PM"){
                    ampm = "PM";
                }
              cout << "Current time logged in" << endl;
              cout << month << "/" << day << "/" << year << " " << hour << ":" << mintue << " " << ampm << endl;
              logHoursClass tempHours(month, day, year, hour, mintue, ampm, labSection);
              for(int i = 0; i < userINFO.size(); i++){
                  if(currentUser.getUsername() == userINFO[i].getUsername()){
                    userINFO[i].setHoursIN(tempHours);
                  }
                }
              }
              else if(inOrOutCheck == 2){
              cout << "Please enter the Lab section you would like to log hours... " << endl;
              cin >> labSection;
              cout << "Please enter the following MM/DD/YYYY " << endl;
              scanf("%d/%d/%d", &month, &day, &year);
              cout << "Please enter the following HH:MM" << endl;
              scanf("%d:%d", &hour,&mintue);
              cout << "AM or PM" << endl;
              cin >> ampm;
                if(ampm == "AM"){
                    ampm = "AM";
                }
                else if(ampm == "PM"){
                    ampm = "PM";
                }
                cout << "Current time logged out" << endl;
                cout << month << "/" << day << "/" << year << "/" << hour << " " << hour << ":" << mintue << " " << ampm << endl;
                logHoursClass tempHours(month, day, year, hour, mintue, ampm, labSection);
                for(int i = 0; i < userINFO.size(); i++){
                  if(currentUser.getUsername() == userINFO[i].getUsername()){
                    userINFO[i].setHoursOUT(tempHours);
                  }
                }
              }
              
          }
          else if(flagCheck == 2){
            break;
          }
          else if(flagCheck == 3){
            string labSectionName;
            vector <logHoursClass> tempHoursIn;
            vector <logHoursClass> tempHoursOut;
            cout << "Type the lab name which hours you'd like to view..." << endl;
            cin >> labSectionName;
            for(int i = 0; i < userINFO.size(); i++){
                  if(currentUser.getUsername() == userINFO[i].getUsername()){
                    tempHoursIn = userINFO[i].getHoursIn();
                    tempHoursOut = userINFO[i].getHoursOut();
                  for(int j = 0; j < tempHoursIn.size(); j++){
                      if(tempHoursIn[j].getLabSection() == labSectionName){
                          cout << tempHoursIn[j].getMonth() << "/" << tempHoursIn[j].getDay() << "/" << tempHoursIn[j].getYear() << " " << tempHoursIn[j].getHour() << ":" << tempHoursIn[j].getMintue() << " " << tempHoursIn[j].getAmPm()  << endl;
                      }
                    }
                    for(int r = 0; r < tempHoursOut.size(); r++){
                      if(tempHoursOut[r].getLabSection() == labSectionName){
                          cout << tempHoursOut[r].getMonth() << "/" << tempHoursOut[r].getDay() << "/" << tempHoursOut[r].getYear() << " " << tempHoursOut[r].getHour() << ":" << tempHoursOut[r].getMintue() << " " << tempHoursIn[r].getAmPm() <<endl;
                      }
                    }
                  }
            }
          }
      }while(yesOrNo != 'X');
    }
    else if(checkAdmin(tempAdmin) == true){
      currentAdmin = currAdmin(tempAdmin);
      currentAdmin.setUserInfo(passUsers());
      adminMenu(currentAdmin);
    }
    else{
      cout << "No account was found..." << endl;
      cout << "Would you like to try again or make a new account? " << endl;
      cout << "Please type Y to try again or type C to create a new account or type X to exit the program " << endl;
      cin >> yesOrNo;
      if(yesOrNo == 'Y'){
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
      }
      else if(yesOrNo == 'C'){
        createAccount();
      }
     }
    }
    else if(signInOrNot == 'X'){
        yesOrNo = 'X';
    }
  }while(yesOrNo != 'X');
};


void loggerClass::storeUserInfo(logUser user){
  userINFO.push_back(user);

};

void loggerClass::storeAdminInfo(loggerAdmin admin){
  adminINFO.push_back(admin);
};

void loggerClass::setUserInfo(vector <logUser> passedInfo){
  this->userINFO = passedInfo;
};

void loggerClass::setLabs(vector <string> labSections){
  this->labSections =labSections;
};

vector <string> loggerClass::getCurrLabs(){
  return labSections;
};

vector <logUser> loggerClass::passUsers(){
  return userINFO;
};

