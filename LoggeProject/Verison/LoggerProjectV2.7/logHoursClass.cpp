#include "logHoursClass.h"

logHoursClass::logHoursClass(int month, int day, int year, int hour, int mintue, string ampm, string labSection){
  this->month = month;
  this->day = day;
  this->year = year;
  this->hour = hour;
  this->mintue = mintue;
  this->ampm = ampm;
  this->labSection = labSection;
};

int logHoursClass::getMonth(){
  return month;
};

int logHoursClass::getDay(){
  return day;
};

int logHoursClass::getYear(){
  return year;
};

int logHoursClass::getHour(){
  return hour;
};

int logHoursClass::getMintue(){
  return mintue;
};

string logHoursClass::getAmPm(){
  return ampm;
};

string logHoursClass::getLabSection(){
  return labSection;
};


void logHoursClass::setMonth(int month){
  this->month = month;
};

void logHoursClass::setDay(int day){
  this->day = day;
};

void logHoursClass::setYear(int year){
  this->year = year;
};

void logHoursClass::setHour(int hour){
  this->hour = hour;
};

void logHoursClass::setMintue(int mintue){
  this->mintue = mintue;
};

void logHoursClass::setAmPm(string ampm){
  this->ampm = ampm;
}

void logHoursClass::setLabSection(string labSection){
  this->labSection = labSection;
}