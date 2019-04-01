#ifndef SUPPORTIVEMETHODS_H
#define SUPPORTIVEMETHODS_H
#include <iostream>
#include <algorithm>
#include <sstream>
#include <time.h>
#include <string>

using namespace std;
class SupportiveMethods{


public:
   static string getTxtLine();
   static char verifyChar();
   static string convertFloatToStr(float nr);
   static string convertIntToStr(int nr);
   static int convertStringToInt(string strNr);
   static string strCurrentDate(char key);
   static bool verifyUserDate(string strUserDate);
   static bool leapYear(string year);
   static string removePauses(string strTransDate);
   static bool verifyAmount(string strAmount);
   static string swapCommaWithDot(string strAmount);
};

#endif
