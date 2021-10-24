#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct record{
    string id,name;
    int grade;
};
int N;
int tag;
vector<record> vec;

bool cmp1(record r1,record r2)
{
    return r1.id < r2.id;
}
bool cmp2(record r1,record r2)
{
    if(r1.name !=r2.name)
        return r1.name<r2.name;
    else return r1.id<r2.id;
}
bool cmp3(record r1,record r2)
{
    if(r1.grade !=r2.grade)
        return r1.grade<r2.grade;
    else return r1.id<r2.id;
}

int main()
{
    cin>>N>>tag;
    for(int i=0;i<N;i++)
    {
        record r;
        cin>>r.id>>r.name>>r.grade;
        vec.emplace_back(r);
    }
    if(tag==1)
    {
        sort(vec.begin(),vec.end(),cmp1);
    }
    else if(tag==2)
    {
        sort(vec.begin(),vec.end(),cmp2);
    }
    else if(tag==3)
    {
        sort(vec.begin(),vec.end(),cmp3);
    }
    for(auto x:vec)
    {
        cout<<x.id<<' '<<x.name<<' '<<x.grade<<endl;
    }

    return 0;
}