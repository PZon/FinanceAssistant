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

string SupportiveMethods::convertFloatToStr(float nr){
    ostringstream buff;
    buff<<nr;
    return buff.str();
}

string SupportiveMethods::convertIntToStr(int nr){
    ostringstream buff;
    buff << nr;
    string str = buff.str();
    return str;
}

int SupportiveMethods::convertStringToInt(string strNr){
    int intNr;
    istringstream buff(strNr);
    buff >> intNr;

    return intNr;
}

string SupportiveMethods::strCurrentDate(char key){
    string strDate,strY,strM,strD, strMPrev, strYPrev;
    time_t timeNow=time(0);
    int year, month, day;

    tm *dateYMD=localtime(&timeNow);
    year=1900+dateYMD->tm_year;
    month=1+dateYMD->tm_mon;
    day=dateYMD->tm_mday;

    strY=convertIntToStr(year);
    strM=convertIntToStr(month);
    strD=convertIntToStr(day);
    strMPrev=convertIntToStr(month-1);
    strYPrev=convertIntToStr(year-1);
    if(strM.length()==1) strM='0'+strM;
    if(strMPrev.length()==1) strMPrev='0'+strMPrev;
    if(strD.length()==1) strD='0'+strD;

    if(key=='-')strDate=strY+'-'+strM+'-'+strD;
    else if(key=='0') strDate=strY+strM+strD;
    else if(key=='Y') strDate=strY;
    else if(key=='M') strDate=strM;
    else if(key=='D') strDate=strD;
    else if(key=='P'){
      if(strMPrev=="00"){
        strMPrev="12";
        strDate=strYPrev+strMPrev+strD;
      }else strDate=strY+strMPrev+strD;
    }
    return strDate;
}

bool SupportiveMethods::verifyUserDate(string strUserDate){
    string strUserYear, strUserMonth, strUserDay;
    for(int i=0; i<4; i++){
        strUserYear+=strUserDate[i];
    }
    for(int i=5; i<7; i++){
        strUserMonth+=strUserDate[i];
    }
    for(int i=8; i<10; i++){
    strUserDay+=strUserDate[i];
    }
    //cout<<strUserYear<<"/"<<strUserMonth<<"/"<<strUserDay<<endl;

    if(strUserDate.length()!=10) /*cout<<"za malo znakow";*/return false;
    else if(strUserDate[4]!='-'&&strUserDate[7]!='-') /*cout<<"brak -";*/return false;
    else if(convertStringToInt(strUserYear)<2000) /*cout<<"rok < 2000";*/return false;
    else if(convertStringToInt(strUserYear)>convertStringToInt(strCurrentDate('Y'))) /*cout<<"rok>2019";*/return false;
    else if(convertStringToInt(strUserMonth)>12) /*cout<<"miesiac > 12";*/return false;
    else if(convertStringToInt(strUserMonth)==1&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==3&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==5&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==7&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==8&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==10&&convertStringToInt(strUserDay)>31||
            convertStringToInt(strUserMonth)==12&&convertStringToInt(strUserDay)>31) /*cout<<"miesiac>31 dni";*/return false;
    else if(convertStringToInt(strUserMonth)==4&&convertStringToInt(strUserDay)>30||
            convertStringToInt(strUserMonth)==6&&convertStringToInt(strUserDay)>30||
            convertStringToInt(strUserMonth)==9&&convertStringToInt(strUserDay)>30||
            convertStringToInt(strUserMonth)==11&&convertStringToInt(strUserDay)>30)/*cout<<"miesiac>30 dni";*/return false;
    else if(convertStringToInt(strUserYear)==convertStringToInt(strCurrentDate('Y'))&&
            convertStringToInt(strUserMonth)>convertStringToInt(strCurrentDate('M')))/*cout<<"data z przyszlosci";*/return false;
    else if(convertStringToInt(strUserYear)==convertStringToInt(strCurrentDate('Y'))&&
            convertStringToInt(strUserMonth)==convertStringToInt(strCurrentDate('M'))&&
            convertStringToInt(strUserDay)>convertStringToInt(strCurrentDate('D')))/*cout<<"data z przyszlosci";*/return false;
    else if(leapYear(strUserYear)==false && convertStringToInt(strUserMonth)==2&&convertStringToInt(strUserDay)>28){
        /*cout<<"miesiac> 28 dni";*/return false;}
    else if(leapYear(strUserYear)==true && convertStringToInt(strUserMonth)==2&&convertStringToInt(strUserDay)>29){
        /*cout<<"miesiac > 29 dni";*/return false;}
    else return true;
}

bool SupportiveMethods::leapYear(string year){
    int intYear=convertStringToInt(year);
    if((intYear%4==0 && intYear%100!=0) || intYear%400==0) return true;
	else return false;
}

string SupportiveMethods::removePauses(string strTransDate){
    string transDate="";
    for(int i=0; i<strTransDate.length(); i++){
        if(strTransDate[i]!='-'){
            transDate+=strTransDate[i];
        }else continue;
    }
    return transDate;
}

bool SupportiveMethods::verifyAmount(string strAmount){
    int noneDigitNr=0;
     for (int i=0; i<strAmount.length(); i++){
        if(!(isdigit(strAmount[i]))) noneDigitNr++;
    }
    if(noneDigitNr>1)return false;
    else return true;
}

string SupportiveMethods::swapCommaWithDot(string strAmount){
    int index=0;
    index=strAmount.find(',');
    if(index>0){
        strAmount.replace(index,1,1,'.');
    }
    return strAmount;
}

int SupportiveMethods::getDate(char key){
    string strDate;
    int intDate,startDate, endDate;

    if(key=='C'){
        strDate=strCurrentDate('0');
    }else if(key=='P'){
        strDate=strCurrentDate('P');
    }
    intDate=convertStringToInt(strDate);
    startDate=intDate-(intDate%100)+1;
    return startDate;
}

string SupportiveMethods::addDashToDate(int intDate){
    string strDate;
    strDate=convertIntToStr(intDate);
    strDate.insert(4,1,'-');
    strDate.insert(7,1,'-');
    return strDate;
}
