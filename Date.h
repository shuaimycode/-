#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int y=1,int m=1,int d=1);

    Date(Date & );

    void setYear(int y);

    int getYear();

    void setMonth(int m);

    int getMonth();

    void setDay(int y);

    int getDay();

    void tomorrow();

    void yesterday();

    void printMonthCalendar();

    void chineseFormat();

    void americaformat();

    int isLeapYear();

    int weekDay();

    ~Date();
};

#endif // DATE_H_INCLUDED
