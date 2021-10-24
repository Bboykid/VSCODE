#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 4;

bool cmp(int a, int b)
{
    return a > b;
}

void to_array(int x, int num[])
{
    for (int i = i; i < N; i++)
        {
            num[i] = x % 10;
            x = x / 10;
        }
}

int to_num(int num[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = sum * 10 + num[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int x;
    int num[N];
    int Max,Min;
    scanf("%d",&x);
    while (1)
    {
        to_array(x,num);
        sort(num,num+4);
        Min = to_num(num);
        sort(num,num+4,cmp);
        Max = to_num(num);

        x = Max - Min;
        printf("%04d - %04d = %04d\n",Max,Min,x);
        if( x== 6174 || x == 0) break;
    }

    return 0;
}
