#include <iostream>
#include "SupportiveMethods.h"

using namespace std;

string SupportiveMethods::getTxtLine(){
    string txt="";
    getline(cin,txt);
    return txt;
}

char SupportiveMethods::verifyChar(){
    string txt;
    char digit={0};
      while (true){
        getline(cin, txt);

        if (txt.length() == 1){
            digit = txt[0];
            break;
        }
        cout << "\nSorry wrong choice. Try again." << endl;
    }
    return digit;
}
