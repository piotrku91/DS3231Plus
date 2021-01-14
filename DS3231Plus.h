#pragma once
#include <DS3231.h>

/* My extension of DS3231 library (https://github.com/NorthernWidget/DS3231) */

class DS3231Plus: public DS3231
{
  public:
bool Century=false;
bool h12;
bool PM;

// Constructor
DS3231Plus() {};
DS3231Plus(DS3231Plus&)=delete; 
DS3231Plus(DS3231Plus&&)=delete; 

// Delay and call functions
void DelayRTCLock(const int& Miliseconds,void (*func_todo)());
void DelayRTCLock(const int& Miliseconds);

// Get functions
String GetTimeString(bool ShowDate=true,bool ShowDow=true,bool ShowTime=true);
String GetAlarmStatusString();

// Set functions
void SetFullTime(const int& Year, const int& Month, const int& Day, const int& DayOfWeek, const int& Hour, const int& Minute, const int& Second);
void SetTime(const int& Hour, const int& Minute, const int& Second);
void SetDate(const int& Year, const int& Month, const int& Day, const int& DayOfWeek);

};
