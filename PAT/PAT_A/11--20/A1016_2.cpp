#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


struct record{
    int dd,hh,mm,t;
    string tag;
};

double price[24];
int N;
map<string,vector<record>> M;

bool cmp(record r1,record r2)
{
    return r1.t<r2.t;
}


int main()
{
    int i,j,k;
    int month;
    for(i=0; i<24;i++)
    {
        cin>>price[i];
    }
    cin>>N;
    for(i=0;i<N;i++)
    {
        string name,tag;
        char c;
        int date,hour,minute;
        cin>>name>>month>>c>>date>>c>>hour>>c>>minute>>tag;
        record temp;
        temp.dd = date;
        temp.mm = month;
        temp.hh = hour;
        temp.mm = minute;
        temp.tag = tag;
        temp.t = date*1440 +hour*60 +minute;
        M[name].emplace_back(temp);
    }
    for(auto it=M.begin(); it!=M.end(); it++)
    {
        auto V = it->second;
        sort(V.begin(),V.end(),cmp);
        double total=0;
        for(i=0;i<V.size();)
        {
            if(i+1<V.size() && V[i].tag>V[i+1].tag)
            {
                if(!total)  //第一次配对成功
                {
                    cout<<it->first;
                    printf(" %02d\n",month); 
                }
                int t1 = V[i].t;
                int t2 = V[i+1].t;
                double single=0;
                for(int Time=t1;Time<t2;++Time)
                {
                    single += price[Time%1440/60];
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",V[i].dd,V[i].hh,V[i].mm,V[i+1].dd,V[i+1].hh,V[i+1].mm, V[i+1].t-V[i].t, single/100);
                i+=2;
                total += single;
            }
            else
            {
                i++;
            }
        }
        if(total)
            printf("Total amount: $%.2f\n",total/100);
    }

}