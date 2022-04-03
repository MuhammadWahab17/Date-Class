//
//  date.h
//  dummy
//
//  Created by Ch Muhammad Wahab on 03/04/2022.
//  Copyright © 2022 Ch Muhammad Wahab. All rights reserved.
//

#ifndef date_h
#define date_h
#include<iostream>
using namespace std;

class date {
    int day,month,year;
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool IsLeap(int y){
        return y%4 == 0 && y %100!=0;
    }
public:
    
    date(int day,int month,int year){
        this->day = day < 1 ? 1 : day;
        this->month = month < 1 ? 1 : month;
        this->year = year < 1 ? 1 : year;
    }

    date(int days,int year){
        this->year = year < 1 ? 1 : year;
        if(IsLeap(this->year)){
            daysInMonth[1] = 29;
        }
        day = month = 1;
        if(days < 1){
            return;
        }
        for(int i=0;days > daysInMonth[i]; i = month-1){
            this->year += (month = (month % 12) + 1) == 1 ? 1 : 0;
            days -= daysInMonth[i];
        }
        day = days;
    }
    
    int daysUntilDate(int day,int month){
        int days = 0;
        for(int i=0;i<month-1;i++){
            days +=daysInMonth[i];
        }return days+day;
    }
    
    
//    1/1/2020 31
//    10 30
    void addDays(int days){
        for(int i=month-1;days > (daysInMonth[i]-day); i = month-1){
            this->year += (month = (month % 12) + 1) == 1 ? 1 : 0;
            days -= daysInMonth[i];
        }
        day += days;
    }

//    1/3/2020
//    29
    void subDays(int days){
        for(int i = month-1;days >= day;i = month-1){
            year -= ( month = month - 1 < 1 ? 12 : month - 1 ) == 12 ? 1 : 0 ;
            days -= daysInMonth[i-1];
        }
        day -= days;
    }
    
    void operator ++ (){
        addDays(1);
    }
    
    void operator -- (){
        subDays(1);
    }
    
    void operator ++ (int dummy){
        addDays(1);
    }
    
    void operator -- (int dummy){
        subDays(1);
    }
    
    bool operator < (date d){
        return year < d.year || (year == d.year && month < d.month) || (year == d.year && month == d.month && day < d.day);
    }

    bool operator > (date d){
        return year > d.year || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day);
    }
    
    bool operator == (date d){
        return year == d.year && month == d.month && d.day == day;
    }

    bool operator != (date d){
        return year != d.year || month || d.month || d.day != day;
    }

    friend ostream& operator << (ostream& out, date d){
        out<<d.day<<"/"<<d.month<<"/"<<d.year;
        return out;
    }
    
    
};

#endif /* date_h */
