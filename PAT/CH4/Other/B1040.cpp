#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin,str);
    int length = str.length();
    int left[maxn]= {0};
    
    for (int i = 0; i < length; i++)
    {
        if (i > 0)
        {
            left[i] = left[i-1];
        }
        if(str[i] == 'P')
        {
            left[i]++;
        }
        
    }
    
    int right_num = 0,ans = 0;
    for (int j = length - 1; j >= 0; j--)
    {
        if (str[j] == 'T')
        {
            right_num++;
        }
        else if (str[j] == 'A')
        {
            ans = (ans + (left[j] * right_num)) % mod;
        }
        
    }
    cout<<ans;

    return 0;
}
