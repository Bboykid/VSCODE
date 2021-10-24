#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int price[24];  //每个时间段的通话价格
int N;          //记录数
struct record {
    string Time;    //时间
    string Type;    //类型，on / off
};

map<string,vector<record>> m;// key1:通信人 key2:通信人的通话记录


bool cmp(record r1,record r2)
{
    if(r1.Time< r2.Time)
        return true;
    else 
        return false;
}


int main()
{

    string name,time,type;  //通话记录的 姓名，时间，性质
    record temp;
    for(int i=0; i<N; i++)
    {
        cin>>name>>time>>type;
        temp.Time = time;
        temp.Type = type;
        m[name].emplace_back(temp);
    }
    //输入结束
    //对每个人的通话记录按时间进行排序
    for(auto &x : m)
    {
        sort(x.second.begin(),x.second.end(),cmp);  //按升序对每个vector排序
    }
    


}