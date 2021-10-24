#include<iostream>
#include<math.h>
using namespace std;




int main(int argc, char const *argv[])
{
    int a,b;
    int res;
    cin>>a>>b;
    res = a + b;
    // cout<<res;
    int m1,m2,m3;
    if(res<0)
    {
        cout<<'-';
        res *=-1;
    }
    m1 = res/1000000;
    m2 = (res - m1*1000000)/1000;
    m3 = res%1000;
    if(m1!=0)
    {
        cout<<m1<<',';
    }
    if(m2!=0)
    {
        cout<<m2<<',';
    }
    cout<<m3;

    return 0;
}
