#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/**
 * @brief 进制转换问题
 * 
 * 数:N1 进制 K1
 * 数:N2 进制未知 (K2) 
 * 
 * N1=N2  -> K2=K1
 * 
 * N2 > N1的情况
 * 从2~K1-1循环，判断每个进制两个值是否相等
 * 
 * N2 < N1
 *  K2~[K1,N1]
 * 
 * 进制转换时的比较问题
 * 对于给定进制的数: 转换为2进制
 * 
 */

int toDigit(char x)
{
    int rnt;
    if(x>='0' && x<='9')
        rnt = x-'0';
    else if( x>='a' && x<='z')
        rnt = x-'a'+10;
    
    return rnt;
}

int translate(string N, int r)
{
    int sum = 0;
    int weight=1;
    for(int i=N.size()-1; i>=0; i--)
    {
        int x=toDigit(N[i]);
        sum+= x*weight;
        weight*=r;
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    string N1,N2;
    int tag,r1,r2;
    cin>>N1>>N2>>tag>>r1;
    if(tag == 2)
    {
        auto a = N1;
        N1 = N2;
        N2 = a;
    }
    int value = translate(N1,r1);
    
    //找出N2中每位最大的数字
    int Maxdigit=0;
    for(char c:N2)
    {
        int j = toDigit(c);
        if( j>Maxdigit)
            Maxdigit = j;
    }
    for( r2=Maxdigit+1; translate(N2,r2)<value ;r2++);
    if( value == translate(N2,r2))
        cout<<r2;
    else
        cout<<"Impossible";


    return 0;
}





