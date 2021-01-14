#include "DS3231Plus.h"

/* My extension of DS3231 library (https://github.com/NorthernWidget/DS3231) */

void DS3231Plus::DelayRTCLock(const int& Miliseconds,void (*func_todo)())
{
   setA1Time(getDoW(), getHour(h12,PM), getMinute(), getSecond()+(Miliseconds/1000), 0x0, true, false, false);
   turnOnAlarm(1);
      while (!checkIfAlarm(1)) {func_todo(); delay(1000);};
};

void DS3231Plus::DelayRTCLock(const int& Miliseconds)
{
   setA1Time(getDoW(), getHour(h12,PM), getMinute(), getSecond()+(Miliseconds/1000), 0x0, true, false, false);
   turnOnAlarm(1);
      while (!checkIfAlarm(1)) {delay(1000);}
};


String DS3231Plus::GetAlarmStatusString()
{
  return "";
}

String DS3231Plus::GetTimeString(bool ShowDate,bool ShowDow,bool ShowTime)
{
    String TimeStamp;
    int h= getHour(h12,PM);
    int m= getMinute();
    int s= getSecond();
    int y= getYear();
    int mo= getMonth(Century); 
    int d= getDate();
    int dow= getDoW();

    
// Date
if (ShowDate) {
     TimeStamp+=y;
     TimeStamp+="/";
     if (mo<10) TimeStamp+="0";
     TimeStamp+=mo;
     TimeStamp+="/";
      if (d<10) TimeStamp+="0";
     TimeStamp+=d;
     TimeStamp+=" ";
}
 
// Day of week
if (ShowDow) {
  TimeStamp+="(";
  TimeStamp+=dow;
  TimeStamp+=")";
  TimeStamp+=" ";
}

// Time
if (ShowTime) {
  if (h<10) TimeStamp+="0";
  TimeStamp+=h;
  TimeStamp+=":";
  if (m<10) TimeStamp+="0";
  TimeStamp+=m;
  TimeStamp+=":";
  if (s<10) TimeStamp+="0";
  TimeStamp+=s;

};
  
  return TimeStamp;
}

void DS3231Plus::SetFullTime(const int& Year, const int& Month, const int& Day, const int& DayOfWeek, const int& Hour, const int& Minute, const int& Second)
{
  setYear(Year);
  setMonth(Month);
  setDate(Day);
  setDoW(DayOfWeek);
  setHour(Hour);
  setMinute(Minute);
  setSecond(Second);
};

void DS3231Plus::SetTime(const int& Hour, const int& Minute, const int& Second)
{
  setHour(Hour);
  setMinute(Minute);
  setSecond(Second);
};

void DS3231Plus::SetDate(const int& Year, const int& Month, const int& Day, const int& DayOfWeek)
{
  setYear(Year);
  setMonth(Month);
  setDate(Day);
  setDoW(DayOfWeek);
};
