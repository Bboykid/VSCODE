/**
 * @file codeup1928.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-22
 * 
 * @copyright Copyright (c) 2021
 *
题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值

样例输入 Copy
20130101
20130105
样例输出 Copy
5
 * 
 */

#include<iostream>
using namespace std;

int dayOfMonth[13][2]= {
    {0,0},{30,30},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};

bool isLeap(int year)
{
    return ((year%4==0 && year%100!=0) || year % 400 == 0);
}

void divideTime(int time,int &year, int &month, int &day)
{
    year = time/10000;
    month = (time % 10000) /100;
    day = time % 100;
}

int main(int argc, char const *argv[])
{
    /* code */
    int time1,time2,year1,year2,month1,month2,day1,day2;
    int ans = 0;
    int tag;
    cin>> time1;
    cin>> time2;
    if(time1 < time2)
    {
        int temp = time1;
        time1 = time2;
        time2 = temp;
    }
    divideTime(time1,year1,month1,day1);
    divideTime(time2,year2,month2,day2);
    
    

    //year2+1 ~ year-1 的天数
    if(year1 - year2 >= 1)
    {
        if(year1 - year2 >1 )
        {
            for(int i = year2+1; i < year1; i++)
            {
                    if(isLeap(i))
                {
                    ans += 366;
                }
                else
                    ans+= 365;
        }
        }
        // year1的天数
        tag = isLeap(year1)? 1:0;
        ans += day2;
        for(int i = 1 ; i < month1; i++)
        {
            ans += dayOfMonth[i][tag];
        }
        
         tag = isLeap(year2)? 1:0;
         ans += (dayOfMonth[month2][tag] -day2 + 1);
        for(int i = month2 +1 ; i<=12; i++)
        {
            ans += dayOfMonth[i][tag];
        }

    }
    else
    {
        int temp1 = 0,temp2 = 0;
        tag = isLeap(year1)? 1:0;
        temp1 += day1;
        for(int i = 1 ; i < month1; i++)
        {
            temp1 += dayOfMonth[i][tag];
        }
        
        tag = isLeap(year2)? 1:0;
        temp2 += day2;
        for(int i = 1 ; i < month2; i++)
        {
            temp2 += dayOfMonth[i][tag];
        }

        ans = temp1 -temp2;

    }    
    ans++;
    cout<<ans;    

    return 0;
}
