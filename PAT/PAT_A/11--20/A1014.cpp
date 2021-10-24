#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxN=1010;
const int Start=480;
const int Hour=60;
const int MaxN=20;

struct customer {
    int process_time,leave_time=0;
};

int N,M,K,Qn;    //窗口数N，每个窗口人数M，总人数K，查询数Q
vector<customer> c(maxN);

void toTime(int x)
{
    int hour = x/60;
    int minute = x%60;
    if( hout>=17 && minute>=0 ) {
        printf("Sorry!\n");
    }else
    printf("%02d:%02d\n",hour,minute);
}

int main()
{
    int i,j;
    cin>>N>>M>>K>>Qn;

    //输入每个用户的业务处理时间
    for(i=1; i<=K ;i++)
    {
        cin>>c[i].process_time;
        c[i].leave_time = 1500;
    }
    //初始化几个8:00服务的顾客的leave_time
    for(int i=1; i<=N;i++) {
        c[i].leave_time = Start+c[i].process_time;
    }

    //N个窗口前的排队队列
    queue<int> Q[MaxN];
    int Time;
    int index = 1;
    for(Time =Start;Time<=1020;Time++)
    {
      
        for(int i=0; i<N; i++) {
            int t = Q[i].front();
              //业务办理完成，出队
            if(Time == c[t].leave_time) {
                //出队列
                Q[i].pop();
               if(Q[i].size()!=0) { 
                   c[Q[i].front()].leave_time = c[t].leave_time + c[Q[i].front()].process_time;
               }
            }
        }
        //入队

        while(index <= K) {
            //找出人数最少的队
            int Min=0;
            for(int i=1;i<N;i++) {
                if(Q[i].size() < Q[Min].size() )
                    Min=i;
            }
            if(Q[Min].size() < M) {
                Q[Min].push(index);
                index++;
            }else {
                break;
            }
       }
    }

//     cout<<"----------------------------"<<endl;
//     for(int i=1; i<=K; i++){
//         cout<<c[i].leave_time<<endl;
//     }
    for(int i = 0;i<Qn;i++) {
        int x;
        cin>>x;
        toTime(c[x].leave_time);
    }

    return 0;
}