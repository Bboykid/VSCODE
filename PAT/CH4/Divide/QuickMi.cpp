/**
 * @file QuickMi.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-23
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 * 快速幂
 * 求 a的b次方 mod m
 */

// primitive method
typedef long long LL;
LL LLpow(LL a, LL b, LL m)
{
    LL ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a % m;
    }
    return ans;
}


//快速幂的思想
// b分奇数偶数讨论

// 二分法
LL binaryPow(int a, int b, int m)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b&1)
    {
        return a*binaryPow(a,b-1,m)%m;
    }
    else
    {
        LL mul = binaryPow(a,b/2,m);
        return mul * mul % m;
    }

}


LL binaryPow2(LL a, LL b, LL m)
{
    LL ans =1;
    while (b > 0)
    {
        if( b & 1 )//b为奇数
            ans = ans * a % m;
        a = a * a % m;
        b = b/2;
    }

    return ans;
}