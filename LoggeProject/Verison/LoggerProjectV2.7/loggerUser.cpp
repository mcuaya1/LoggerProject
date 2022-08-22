#include "loggerUser.h"
#include "logHoursClass.h"
#include <string>
#include <iostream>
using namespace std;

//LOGUSER OBJECT
logUser::logUser(string userName, string userPassword, int studentID){
  this->userName = userName;
  this->userPassword = userPassword;
  this->studentID = studentID;
};


//SETTERS
void logUser::setUsername(string userName){
  this->userName = userName;
};

void logUser::setUserPassword(string userPassword){
  this->userPassword = userPassword;
};

void logUser::setStudentID(int studentID){
  this->studentID = studentID;
};


void logUser::viewHoursIn(){
  //cout << "Hours logged in..." << endl;
  for(int i = 0; i < user1HoursIN.size(); i++){
    cout << user1HoursIN[i].getMonth() << "/" << user1HoursIN[i].getDay() << "/" << user1HoursIN[i].getYear() << " " << user1HoursIN[i].getHour() << ":" << user1HoursIN[i].getMintue() << " " << user1HoursIN[i].getAmPm() << endl;
  }
};

void logUser::viewHoursOut(){
  //cout << "Hours logged out..." << endl;
  for(int i = 0; i < user1HoursIN.size(); i++){
    cout << user1HoursOUT[i].getMonth() << "/" << user1HoursOUT[i].getDay() << "/" << user1HoursOUT[i].getYear() << " " << user1HoursOUT[i].getHour() << ":" << user1HoursOUT[i].getMintue() << " " << user1HoursOUT[i].getAmPm() << endl;
  }
};


void logUser::setHoursIN(logHoursClass hoursIN){
  user1HoursIN.push_back(hoursIN);

}

void logUser::setHoursOUT(logHoursClass hoursOUT){
  user1HoursOUT.push_back(hoursOUT);

}

void logUser::setListHoursOUT(vector <logHoursClass> hoursOUT){
  this->user1HoursOUT = hoursOUT;

}

void logUser::setListHoursIN(vector <logHoursClass> hoursIN){
  this->user1HoursIN = hoursIN;

}

void logUser::setCurrLabs(vector<string> labSections){
  this->labSections = labSections;
}

void logUser::viewLabs(){
  for(int i = 0; i < labSections.size(); i++){
    cout << "Lab: " << labSections[i] << endl;
  }
};

//ACCESSORS
string logUser::getUsername(){
  return userName; 
};

string logUser::getUserPassword(){
  return userPassword;
};

int logUser::getStudentID(){
  return studentID;
};

vector <logHoursClass> logUser::getHoursIn(){
  return user1HoursIN;
}

vector <logHoursClass> logUser::getHoursOut(){
  return user1HoursOUT;
}

