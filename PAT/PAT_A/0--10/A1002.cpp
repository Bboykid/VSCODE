#include<iostream>
#include<math.h>
using namespace std;

#define Min 0.1

/**
 * @brief 解法1：设置一个float类型的数组,其下标表示其对应的指数，数组内容存放系数的值
 * 注： 部分正确，不知道哪里出错，缺少测试用例 
 */

int main(int argc, char const *argv[])
{
    float A[1001] ={0};
    int K1,K2;
    float temp;
    int sum =0;
    int Nk;
    cin>>K1;
    for(int i=0; i<K1; i++)
    {
        cin>>Nk;
        cin>>temp;
        A[Nk]+=temp;
        sum++;
    }
    cin>>K2;
    for(int i=0;i<K2;i++)
    {
        cin>>Nk;
        cin>>temp;
        if(A[Nk]==0 && A[Nk]<Min)
        {
            A[Nk]=temp;
            sum++;
        }
        else//已经存在
        {
            A[Nk] +=temp;
            if(A[Nk]==0 && A[Nk]<Min)
                sum--;
        }
    
    }
    cout<<sum<<" ";
    for(int i = 1000 ; i>=0; i--)
    {
        if((A[i]!=0 || A[i]>Min)&& sum>1)
        {
            cout<<i<<" "<<A[i]<<" ";
            sum--;
        }
        else if((A[i]!=0 || A[i]>Min)&&sum==1)
        {
            cout<<i<<" "<<A[i];
        }
    }
    
    return 0;
}
