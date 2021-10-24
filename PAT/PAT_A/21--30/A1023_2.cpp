#include<iostream>
#include<string>
using namespace std;





int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1;        //原串

    int T1[30],T2[30];
    int n=s1.size();
    for(int i=n-1,j=0; i>=0; i--,j++)
    {
        int temp=(int)(s1[i]-'0');
        T1[j] = temp;
    }
    //double
    
    int flag[10]={0};
    for(int i=0 ;i<n;i++)
    {
        flag[T1[i]]=1;//标记为存在
    }


    int a,b,c;    //
    c=0;    //进位
    for(int i=0; i<n; i++ )
    {
        a=T1[i]*2+c;
        if(a>=10)
        {
            c=a/10;
            b = a%10;
        }
        else
        {
            c=0;
            b=a;
        }
        T2[i]=b;
    }
    if(c!=0)
        {
            T2[n]=c;
            n++;
        }

    int tag=1;
    for(int i=0;i<n;i++)
    {
       if( flag[T2[i]]==0 )//原串不存在
       {
           tag=0;
           break;
       }
    }
    if(tag==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    for(int i=n-1; i>=0; i--)
    {
        cout<<T2[i];
    }


    return 0;
}
