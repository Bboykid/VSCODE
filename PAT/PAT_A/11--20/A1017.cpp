#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int Hour=60*60;
const int Minute = 60;

const int Start = 8*Hour;
const int End = 17*Hour;

struct person
{
    int time;
    int process;
};

vector<person> v;
int window[100];
int waiting[10000];
int N,K;

int time_to_int(string s)
{
    int hour,min,sec,time;
    hour =(int)(s[0]-'0')*10+(s[1]-'0');
    min = (int)(s[3]-'0')*10+(s[4]-'0');
    sec = (int)(s[6]-'0')*10+(s[7]-'0');
    time = hour*Hour + min*Minute +sec;
    return time;
}
bool cmp(person p1,person p2)
{
    return p1.time<p2.time;
}
int get_min(int window[])
{
    int index=0;
    for(int i =0; i<K; i++)
    {
        if(window[i]<window[index])
            index = i;
    }
    return index;
}

int main(int argc, char const *argv[])
{
    person tempPerson;
    string ArriveTime;
    int ProcessTime,Arrive;
    cin>>N>>K;
    // cout<<Start<<" "<<End<<endl;
    // cout<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>ArriveTime;
        cin>>ProcessTime;
        Arrive = time_to_int(ArriveTime);
        tempPerson.time = Arrive;
        tempPerson.process=ProcessTime;
        v.emplace_back(tempPerson);
    }
    fill(window,window+K,Start);
    sort(v.begin(),v.end(),cmp);
    int index;
    int cnt=0,sum=0;
    for(int i=0; i<v.size();i++)
    {
       if( v[i].time <= End )
       {
            cnt++;
            index = get_min(window);
            if(window[index] > v[i].time)
            {
                waiting[i] = window[index] - v[i].time;
                window[index] += v[i].process*Minute;
            }
            else
            {
                waiting[i] = 0;
                window[index] = v[i].time + v[i].process*Minute;
            }
            sum+=waiting[i];
       } 
       else {
           break;
       }
    }
    // for(int i =0; i<N; i++)
    // {
    //     cout<<waiting[i]<<endl;
    // }
    float res;
    if(cnt!=0)
        res = (float)(sum*1.0)/(60*cnt);
    else 
        res = 0;
    printf("%.1f",res);
    return 0;
}
