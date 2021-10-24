#include<iostream>
#include<math.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    int sum=0;
    int pre=0;
    int now;
    for(int i=0 ; i<N; i++ )
    {
        cin>>now;
        sum+=5;
        if( now-pre >0 )
        {
            sum+= (now-pre)*6;
        }
        else
        {
            sum+= (pre-now)*4;
        }
        pre = now;
    }
    
    cout<<sum;

    return 0;
}
