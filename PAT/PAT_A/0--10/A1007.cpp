#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF -1000000;
const int MaxN = 10000;


struct node
{
    int    data;
    int begin;
};



int main(int argc, char const *argv[])
{
    int K;
    int num[MaxN];

    cin>>K;

    for(int i=0; i<K; i++)
    {
        cin>>num[i];
    }

    vector<node> dp(K);
    int begin=0,end=0;
    int temp_begin=0,temp_end=0;
    int maxIndex=0;
    int max = num[0];
    dp[0].data=num[0];
    dp[0].begin=0;
    for(int i=1; i<K; i++)
    {
        if(dp[i-1].data+num[i] >= num[i])
        {
            dp[i].data = dp[i-1].data+num[i];
            dp[i].begin = dp[i-1].begin;
        }
        else
        {
            dp[i].data = num[i];
            dp[i].begin = i;
        }
        if( dp[i].data > dp[maxIndex].data )
        {
            maxIndex = i;
        }
    }
    if(dp[maxIndex].data>=0)
        cout<<dp[maxIndex].data<<' '<<num[dp[maxIndex].begin]<<' '<<num[maxIndex];
    else
        cout<<0<<' '<<num[0]<<' '<<num[K-1];


  
    return 0;
}
