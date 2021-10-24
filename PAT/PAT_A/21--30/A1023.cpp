#include<iostream>
#include<string>
#include<vector>
using namespace std;


int flag[10]={0};

int main()
{
    string s;
    cin>>s;
    vector<int> digits;
    for(int i=s.size()-1;i>=0;i--)
    {
        //从后往前
        int temp=(int)(s[i]-'0');
        digits.emplace_back(temp);
    }   
    //double
    vector<int> ToDouble;
    int c=0;    //进位
    for(int i=0;i<digits.size();i++)
    {
        int temp=digits[i]*2 + c;
        if(temp>10)
        {
            c = temp-10;
            temp = temp-10;
        }
        else 
            c=0;
        ToDouble.emplace_back(temp);
    }
    if(c!=0)
        ToDouble.emplace_back(c);
    
    for(auto x:digits)
    {
        flag[x]=1;
    }

    int tag=1;
    for(auto x:ToDouble)
    {
        if(flag[x]==0)  //原串中不存在这个数
        {
            tag=0;
        }
    }
    if(tag==1)
        cout<<"Yes"<<endl;
    else   
        cout<<"No"<<endl;
    
    for(int i=ToDouble.size();i>=0; i--)
    {
        cout<<ToDouble[i];
    }
    
    return 0;
}