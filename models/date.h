#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Date{
  int day;
  int month;
  int year;
  public:
  Date(){
    day = 0;
    month = 0;
    year = 0;
  }
  int getDay();
  void setDay(int);
  int getMonth();
  void setMonth(int);
  int getYear();
  void setYear(int);
};

int Date ::getDay() {
    return day;
}

void Date :: setDay(int day) {
    this->day = day;
}

int Date :: getMonth() {
    return month;
}

void Date :: setMonth(int month) {
    this->month = month;
}

int Date :: getYear() {
    return year;
}

void Date :: setYear(int year) {
    this->year = year;
}

#endif
