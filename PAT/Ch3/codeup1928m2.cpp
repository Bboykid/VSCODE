#include<iostream>
using namespace std;

int month[13][2]= {
    {0,0},{30,30},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};

bool isLeap(int year)
{
    return ((year%4==0 && year%100!=0) || year % 400 == 0);
}

int main(int argc, char const *argv[])
{
    int time1,time2,year1,year2,month1,month2,day1,day2;
    return 0;
}
