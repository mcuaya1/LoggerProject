#include "loggerAdmin.h"
#include "loggerClass.h"
#include "logHoursClass.h"
#include <iostream>
loggerAdmin::loggerAdmin(string adminName, string adminPass){
  this->adminName = adminName;
  this->adminPass = adminPass;
};

void loggerAdmin::setAdminName(string adminName){
  this->adminName = adminName;
};

void loggerAdmin::setAdminPass(string adminPass){
  this->adminPass = adminPass;
};

void loggerAdmin::setUserInfo(vector <logUser> passedInfo){
  this->userINFO = passedInfo;
}

string loggerAdmin::getAdminName(){
  return adminName;
};

string loggerAdmin::getAdminPass(){
  return adminPass;
};

void loggerAdmin::viewUsers(){
  cout << "Current Users" << endl;
  for(int i = 0; i < userINFO.size(); i++){
    cout << "Username: " << userINFO[i].getUsername() << endl;
    cout << "Password: " << userINFO[i].getUserPassword() << endl;
  }
};


vector <logUser> loggerAdmin::passUserInfo(){
  return userINFO;
};

void loggerAdmin::deleteUsers(){
  string userName;
  viewUsers();
  cout << "Type the username of the user which you would like to delete... " << endl;
  cin >> userName;
  for(int i = 0; i < userINFO.size(); i++){
      if(userName == userINFO[i].getUsername()){
        cout << "User has been found and deleted..." << endl;
        userINFO.erase(userINFO.begin() + i);
      }
  }
};

void loggerAdmin::editUsers(){
  string userName;
  string userPass;
  int studentID;
  viewUsers();
  cout << "Type the username of the user which you would like to edit... " << endl;
  cin >> userName;
  for(int i = 0; i < userINFO.size(); i++){
      if(userName == userINFO[i].getUsername()){
        cout << "User has been found..." << endl;
        cout << "Please type the new username " << endl;
        cin >> userName;
        cout << "Please type the new password" << endl;
        cin >> userPass;
        cout << "Please type the new student ID" << endl;
        cin >> studentID;
        userINFO[i].setUsername(userName);
        userINFO[i].setUserPassword(userPass);
        userINFO[i].setStudentID(studentID);
      }
  }
};

void loggerAdmin::viewUserHours(){
  string userName;
  viewUsers();
  cout << "Type the username of the user which hours you'd like to view..." << endl;
  cin >> userName;
  for(int i = 0; i < userINFO.size(); i++){
      if(userName == userINFO[i].getUsername()){
        cout << "Hours logged in..." << endl;
        userINFO[i].viewHoursIn();
        cout << "Hours logged out..." << endl;
        userINFO[i].viewHoursOut();
      }
  }
};

void loggerAdmin::addUserHours(){
  string userName;
  viewUsers();
  int month, day, year, hour, minute;
  string ampm, labSections;
  cout << "Type the username of the user which hours you'd like to add to..." << endl;
  cin >> userName;
  for(int i = 0; i < userINFO.size(); i++){
      if(userName == userINFO[i].getUsername()){
        viewLabs();
        cout << "Please enter the lab section " << endl;
        cin >> labSections;
        cout << "Please enter the following MM/DD/YYYY " << endl;
        scanf("%d/%d/%d", &month, &day, &year);
        cout << "Please enter the following HH:MM" << endl;
        scanf("%d:%d", &hour,&minute);
        cout << "AM or PM" << endl;
        cin >> ampm;
          if(ampm == "AM"){
              ampm = "AM";
           }
          else if(ampm == "PM"){
              ampm = "PM";
           }
          cout << "Current time logged in" << endl;
          cout << month << "/" << day << "/" << year << " " << hour << ":" << minute << " " << ampm << endl;
          logHoursClass tempHoursIn(month,day,year,hour,minute,ampm, labSections);
          userINFO[i].setHoursIN(tempHoursIn);

          viewLabs();
          cout << "Please enter the following MM/DD/YYYY " << endl;
          cin >> labSections;
          scanf("%d/%d/%d", &month, &day, &year);
          cout << "Please enter the following HH:MM" << endl;
          scanf("%d:%d", &hour,&minute);
          cout << "AM or PM" << endl;
          cin >> ampm;
          if(ampm == "AM"){
              ampm = "AM";
          }
          else if(ampm == "PM"){
             ampm = "PM";
          }
          cout << "Current time logged out" << endl;
          cout << month << "/" << day << "/" << year << " " << hour << ":" << minute << " " << ampm << endl;
          logHoursClass tempHoursOut(month, day, year, hour, minute, ampm,labSections);
          userINFO[i].setHoursOUT(tempHoursOut);
      }
  }
};

void loggerAdmin::deleteUserHours(){
  string userName;
  viewUserHours();
  vector <logHoursClass> tempHoursIn;
  vector <logHoursClass> tempHoursOut;
  int index;
  cout << "Type the username of the user which hours you'd like to delete..." << endl;
  cin >> userName;
  for(int i = 0; i < userINFO.size(); i++){
      if(userName == userINFO[i].getUsername()){
        userINFO[i].viewHoursIn();
        userINFO[i].viewHoursOut();
        tempHoursIn = userINFO[i].getHoursIn();
        tempHoursOut = userINFO[i].getHoursOut();
        cout << "Please type the line which you like deleted " << endl;
        cin >> index;
        for(int j = 0; j < tempHoursIn.size(); j++){
          if((index - 1) == j){
            tempHoursIn.erase(tempHoursIn.begin() + j);
          }
        }
        for(int r = 0; r < tempHoursOut.size(); r++){
          if((index - 1) == r){
            tempHoursOut.erase(tempHoursOut.begin() + r);
          }
        }
        userINFO[i].setListHoursOUT(tempHoursOut);
        userINFO[i].setListHoursIN(tempHoursIn);
      }
  }
};

void loggerAdmin::createLab(){
  string lab;
  cout << "Type the name of the lab which you would like to create or add..." << endl;
  cin >> lab;
  labSections.push_back(lab);
};

void loggerAdmin::deleteLab(){
  string lab;
  vector <logHoursClass> tempHoursIN;
  vector <logHoursClass> tempHoursOUT;
  cout << "Type the name of the lab which you like to deleted..." << endl;
  cin >> lab;
  for(int i = 0; i < labSections.size(); i++){
    if(labSections[i] ==  lab){
      labSections.erase(labSections.begin() + i);
    }
  }

  for(int i = 0; i < userINFO.size(); i++){
    tempHoursIN = userINFO[i].getHoursIn();
    tempHoursOUT = userINFO[i].getHoursOut();
    for(int j = 0; j < tempHoursIN.size(); i++){
      if(tempHoursIN[j].getLabSection() == lab){
        tempHoursIN.erase(tempHoursIN.begin() + j);
        userINFO[i].setListHoursIN(tempHoursIN);
      }
    }
    for(int r = 0; r < tempHoursIN.size(); r++){
      if(tempHoursOUT[r].getLabSection() == lab){
        tempHoursOUT.erase(tempHoursIN.begin() + r);
        userINFO[i].setListHoursOUT(tempHoursOUT);
      }
    }
  }
};

void loggerAdmin::editLab(){
  string lab;
  string labEdit;
  vector <logHoursClass> tempHoursIN;
  vector <logHoursClass> tempHoursOUT;
  cout << "Type the name of the lab which you like to edit... " << endl;
  cin >> lab;
  for(int i = 0; i < labSections.size(); i++){
    if(labSections[i] ==  lab){
      cout << "What would you like the lab to be called..." << endl;\
      cin >> labEdit;
      labSections[i] = labEdit;
    }
  }
  for(int i = 0; i < userINFO.size(); i++){
    tempHoursIN = userINFO[i].getHoursIn();
    tempHoursOUT = userINFO[i].getHoursOut();
    for(int j = 0; j < tempHoursIN.size(); i++){
      if(tempHoursIN[j].getLabSection() == lab){
        tempHoursIN[j].setLabSection(labEdit);
        userINFO[i].setListHoursIN(tempHoursIN);
      }
    }
    for(int r = 0; r < tempHoursIN.size(); r++){
      if(tempHoursOUT[r].getLabSection() == lab){
        tempHoursOUT[r].setLabSection(labEdit);
        userINFO[i].setListHoursOUT(tempHoursOUT);
      }
    }
  }
};

vector <string> loggerAdmin::passLabSections(){
  return labSections;
};

void loggerAdmin::viewLabs(){
  for(int i = 0; i < labSections.size(); i++){
    cout << "Lab: " << labSections[i] << endl;
  }
}
