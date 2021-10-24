#include<iostream>
#include<vector>
using namespace std;



int main(int argc, char const *argv[])
{
    int N, b,temp;

    cin>>N>>b;

    //将N转换为b进制的数
    vector<int> s;
    while(N!=0)
    {
        temp = N%b;
        s.emplace_back(temp);
        N = N/b;
    }
    int i,j;
    int flag=1;
    for(i=s.size()-1,j=0; i>=0,j<=i;i--,j++)
    {
        if(s[i]!=s[j])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {  
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    for(int k=s.size()-1;k>=0; k--)
        {
            if(k==s.size()-1)
                cout<<s[k];
            else
                cout<<' '<<s[k];
        }


    return 0;
}
