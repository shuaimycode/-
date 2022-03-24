#include"Date.h"
#include<iostream>
using namespace std;

int const monthDay[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

char * const weekName[7]= {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

char * const monthName[12]= {"Jan","Feb","Mar","Api","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    cout<<"Constructor run"<<endl;
}

Date::Date(Date & a)
{
    year=a.year;
    month=a.month;
    day=a.day;
    cout<<"CopyConstructor run"<<endl;
}

void Date::setYear(int y)
{
    year=y;
}

int Date::getYear()
{
    return year;
}

void Date::setMonth(int m)
{
    if(m<1)
    {
        m=1;
    }
    else
    {
        if(m>12)
        {
            m=12;
        }
    }
    month=m;
}

int Date::getMonth()
{
    return month;
}

void Date::setDay(int d)
{
    if(d<1)
    {
        d=1;
    }
    else
    {
        if(d>31)
        {
            d=31;
        }
    }
    int isleapyear=isLeapYear();
    if(month==2)
    {
        if(isleapyear==1)
        {
            if(d>29)
            {
                d=29;
            }
        }
        else
        {
            if(d>28)
            {
                d=28;
            }
        }
    }
    day=d;
}

int Date::getDay()
{
    return day;
}

void Date::tomorrow()
{
    int d=day;
    if(month==2)
    {
        if(d=29)
        {
            d--;
        }
    }
    if(d==monthDay[month-1])
    {
        switch(d)
        {
        case 31:
            if(month==12)
            {
                day=1;
                month=1;
                year++;
            }
            else
            {
                day=1;
                month++;
            }
            break;
        case 30:
            day=1;
            month++;
            break;
        case 28:
        case 29:
            day=1;
            month++;
        }
    }
    else
    {
        day++;
    }
}

void Date::yesterday()
{
    int isleapyear=isLeapYear();
    if(day==1)
    {
        switch(month)
        {
        case 1:
            day=31;
            year--;
            month=12;
            break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
            day=30;
            month--;
            break;
        case 5:
        case 7:
        case 10:
        case 12:
            day=30;
            month--;
            break;
        case 3:
            if(isleapyear==1)
            {
                day=29;
                month--;
            }
            else
            {
                day=28;
                month--;
            }

        }
    }
    else
    {
        day--;
    }
}

void Date:: printMonthCalendar()
{
    int isleapyear;
    isleapyear=isLeapYear();

    int totaldays;  //当月总天数
    totaldays=monthDay[month-1];

    if(isleapyear==1)   //闰年
    {
        if(month==2)
        {
            totaldays=29;
        }
    }

    for(int i=0; i<7; i++)
    {
        cout<<weekName[i];
    }
    cout<<endl;

    int s=weekDay();
    s=s-(day%7-1);

    for(int i=0; i<s; i++)
    {
        cout<<"   ";
    }

    int a=1;
    for(int j=0; j<7-s; j++,a++)
    {
        cout.width(3);
        cout<<a;
    }
    cout<<endl;

    int sum=0;
    for(; a<=totaldays; a++)
    {
        cout.width(3);
        cout<<a;
        sum++;
        if(sum%7==0)
        {
            cout<<endl;
        }
    }
    cout<<endl;
}

void Date:: chineseFormat()
{
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}

void Date:: americaformat()
{
    cout<<monthName[month-1]<<" "<<day<<","<<year<<endl;
}

int Date::isLeapYear()
{
    if((year%4==0 && year%100!=0) || (year%400==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Date::weekDay()
{
    int w;   //星期
    int c=year/100;  //世纪
    int y=year%100;     //年
    int m=month;   //月
    if(m<3)
    {
        m+=12;
        y--;
    }
    int d=day;       //日
    w=(y+y/4+c/4-2*c+(26*(m+1)/10)+d-1)%7;   //蔡勒公式
    if(w<0)
    {
        w+=7;
    }
    return w;
}
Date::~Date()
{
    cout<<"Destructor run"<<endl;
}
