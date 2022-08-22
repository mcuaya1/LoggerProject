#include <iostream>
#include <string>
#include "loggerUser.h"
#include "loggerClass.h"
using namespace std;
int main() {
  loggerClass test;

  logUser user1("Bob","Bob1234",1234567);
  logUser user2("Bob12","Bob123412",1234567);
  loggerAdmin admin("Tom", "Tom1234");
  test.storeUserInfo(user1);
  test.storeUserInfo(user2);
  test.storeAdminInfo(admin);
  test.menu();

}