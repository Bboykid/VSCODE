#include<iostream>
#include<vector>
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
    vector<int> v;
    while( res!=0 )
    {
        v.emplace_back(res%10);
        res=res/10;
    }
    for(int i = v.size()-1;i>=0;i--)
    {
        cout<<v[i];
        if(i>0 && i%3==0)
            cout<<',';
    }

    return 0;
}
