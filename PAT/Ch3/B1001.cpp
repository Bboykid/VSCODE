#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int count = 0;
    cin>>n;
    while(n!=1)
    {
        if(n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = (3*n + 1)/2;
        }
        count++;
    }
    cout<<count<<endl;
    return 0;
}
