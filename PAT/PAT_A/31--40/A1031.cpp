#include<iostream>
#include<string>

using namespace std;

string s;
int n1,n2,n3,k;
int len;

int main()
{
    cin>>s;
    len = s.length();

    for(n2=3;n2<=len;n2++)
    {
        k = (len - n2 +2)/2;
        if( k<=n2 && (2*k-2+n2 == len))
        {
            n1=n3 = k;
            break;
        }
    }

    // cout<<n1<<' '<<n2<<' '<<n3;
    for(int i=1;i<n1;i++)
    {
        cout<<s[i-1];
        for(int j=0;j<n2-2;j++)
        {
            cout<<' ';
        }
        cout<<s[len-i]<<endl;
    }
    for(int i=0; i<n2;i++)
    {
        cout<<s[n1+i-1];
    }


    return 0;
}