#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;


typedef struct record
{
    string id;
    int C,M,E,A;
    int C_rank,M_rank,E_rank,A_rank;
    int best_rank;
    char best_course;
}record;

bool CmpByA(const record &r1, const record &r2)
{
    return r1.A > r2.A;
}
bool CmpByC(const record &r1, const record &r2)
{
    return r1.C>r2.C;
}
bool CmpByM(const record &r1, const record &r2)
{
    return r1.M>r2.M;
}
bool CmpByE(const record &r1, const record &r2)
{
    return r1.E>r2.E;
}

void Rank(vector<record> &records)
{
    sort(records.begin(),records.end(),CmpByA);
    for(unsigned  i=0;i<records.size();i++)
    {
        if( i>0 && records[i].A == records[i-1].A )
        {
                records[i].A_rank = records[i-1].A_rank;
        }
        else
            records[i].A_rank = i+1;
        // cout<<records[i].id<<":"<<records[i].A_rank<<' '<<records[i].A<<endl;
    }
    sort(records.begin(),records.end(),CmpByC);
    for(unsigned  i=0;i<records.size();i++)
    {
        if( i>0 && records[i].C == records[i-1].C)
        {
                records[i].C_rank = records[i-1].C_rank;
        }
        else
            records[i].C_rank = i+1;
        // cout<<records[i].id<<":"<<records[i].C_rank<<' '<<records[i].C<<endl;
    }
    sort(records.begin(),records.end(),CmpByM);
    for(unsigned  i=0;i<records.size();i++)
    {
        if( i>0 && records[i].M == records[i-1].M)
        {
                records[i].M_rank = records[i-1].M_rank;
        }
        else
            records[i].M_rank = i+1;
        // cout<<records[i].id<<":"<<records[i].M_rank<<' '<<records[i].M<<endl;
    }   
    sort(records.begin(),records.end(),CmpByE);
    for(unsigned  i=0;i<records.size();i++)
    {
        if( i>0 && records[i].E == records[i-1].E)
        {
                records[i].E_rank = records[i-1].E_rank;
        }
        else 
            records[i].E_rank = i+1;
        // cout<<records[i].id<<":"<<records[i].E_rank<<' '<<records[i].E<<endl;
    }   
}


int main()
{
    
    vector<record> records;
    int N,M;
    cin>>N>>M;
    string s;
    record temp;
    int c,m,e,a;
    for(int i=0; i<N; i++)
    {
        cin>>s>>c>>m>>e;
        a = ( c+m+e )/3;
        temp.id = s;
        temp.A =a;
        temp.C =c;
        temp.E = e;
        temp.M = m;
        records.emplace_back(temp);
    }
    // for(auto x:records)
    // {
    //     cout<<x.id<<' '<<x.C<<' '<<x.M<<' '<<x.E<<endl;
    // }
    //输入完成，下面求每个成绩的rank
    Rank(records);
    //求取了所有的科目的rank值
    for( auto &x: records)
    {
        x.best_course='A';
        x.best_rank=x.A_rank;
        if( x.C_rank < x.best_rank )
        {
            x.best_rank=x.C_rank;
            x.best_course='C';
        }
        if( x.M_rank < x.best_rank )
        {
            x.best_rank=x.M_rank;
            x.best_course='M';
        }
        if( x.E_rank < x.best_rank )
        {
            x.best_rank=x.E_rank;
            x.best_course='E';
        }
    }

    // for(auto x:records)
    // {
    //     cout<<x.id<<' '<<x.best_rank<<' '<<x.best_course<<endl;
    // }
 
        vector<string> search;
        for(int i=0; i<M; i++)
        {
            cin>>s;
            search.emplace_back(s);
        }
        map<string,record> map;
        for( auto &x: records )
        {
            s = x.id;
            map[s] = x;
        }
        for(auto k:search)
        {
            if(map.count(k))
                cout<<map[k].best_rank<<' '<<map[k].best_course<<endl;
            else 
                cout<<"N/A"<<endl;
        }

    return 0;
}
