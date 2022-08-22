#ifndef LOGHOURSCLASS_H
#define LOGHOURSCLASS_H
#include <string>
#include <vector>


using namespace std;

class logHoursClass{
  public:
    logHoursClass(int month, int day, int year, int hour, int mintue, string ampm,string labSection);

    void setMonth(int);
    void setDay(int);
    void setYear(int);
    void setHour(int);
    void setMintue(int);
    void setAmPm(string);
    void setLabSection(string);

    int getMonth();
    int getDay();
    int getYear();
    int getHour();
    int getMintue();
    string getAmPm();
    string getLabSection();
    
  private:
    int month;
    int day;
    int year;
    int hour;
    int mintue;
    string labSection;
    string ampm;
    //vector <logINClass> userHoursIN;
    //vector <logINClass> userHoursOUT;
    
};

#endif /* LOGGERUSER_H */