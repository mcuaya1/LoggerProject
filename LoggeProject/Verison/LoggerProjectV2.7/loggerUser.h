#ifndef LOGGERUSER_H
#define LOGGERUSER_H
#include <string>
#include <vector>
#include "logHoursClass.h"
using namespace std;

class logUser{
    public:
        logUser(string, string, int);

        void storeHoursIN();
        void storeHoursOUT();


        string getUsername();
        string getUserPassword();
        int getStudentID();
        vector <logHoursClass> getHoursIn();
        vector <logHoursClass> getHoursOut();
        
        void setUsername(string);
        void setUserPassword(string);
        void setStudentID(int);


        void setListHoursIN(vector <logHoursClass>);
        void setHoursIN(logHoursClass);
        void setListHoursOUT(vector <logHoursClass>);
        void setHoursOUT(logHoursClass); 
        void setCurrLabs(vector <string>);


        void viewHoursIn();
        void viewHoursOut();
        void viewLabs();
    private:
        string userName, 
                userPassword;
        int studentID;
        vector <string> labSections;
        vector <logHoursClass> user1HoursIN;
        vector <logHoursClass> user1HoursOUT;    
};

#endif /* LOGGERUSER_H */