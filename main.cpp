#include<iostream>
#include"Date.h"
using namespace std;

int main()
{
    int year,month,day;
    Date d1;
    Date d2(d1);
    cin>>year>>month>>day;
    d1.setYear(year);
    d1.setMonth(month);
    d1.setDay(day);
    d1.yesterday();
    d1.chineseFormat();
    cin>>year>>month>>day;
    d2.setYear(year);
    d2.setMonth(month);
    d2.setDay(day);
    d2.tomorrow();
    d2.americaformat();
    d2.printMonthCalendar();
    return 0;
}
