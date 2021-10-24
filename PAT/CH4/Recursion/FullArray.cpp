#include<iostream>
using namespace std;

const int maxn = 11;

int n, P[maxn],Exist[maxn] = {false};

void generateP(int index)
{
    //递归边界
    if( index == n + 1 )
    {
        for (int i = 1; i <= n; i++)
        {
            /* code */
            cout<<P[i];
        }
        cout<<endl;
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        /* code */
        if (Exist[x]==false)
        {
            Exist[x] = true;
            P[index] = x;
            generateP(index+1);
            //回归时清除脏数据
            Exist[x] = false;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    n = 3;
    generateP(1);
    return 0;
}

