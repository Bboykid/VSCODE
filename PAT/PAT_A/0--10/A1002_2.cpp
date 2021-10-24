#include<iostream>
#include<cstdio>
#include<map>
using namespace std;


int main(int argc, char const *argv[])
{
    map<int,float> A;
    int K;
    int N;
    float temp;
    cin>>K;
    for(int i = 0; i<K; i++)
    {
        cin>>N>>temp;
        A[N] +=temp;
    }
    cin>>K;
    for(int i = 0; i<K; i++)
    {
        cin>>N>>temp;
        A[N] +=temp;
        if(A[N]==0)
            A.erase(N);
    }
    cout<<A.size();
    for(auto it=A.end();it!=A.begin();)
    {
        --it;
        printf(" %d %.1f",it->first,it->second);
    }

    return 0;
}
