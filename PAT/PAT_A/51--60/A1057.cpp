#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 100010;
const int sqrN = 316; // sqrt(100001)块内元素个数

/**
 * @brief 利用分块的思想
 * 
 */

stack<int> st;
int block[sqrN];//记录每一块中元素的数量
int table[maxn];//记录每一个元素的数量

void Push(int key)
{
    st.push(key);
    block[key/sqrN]++;
    table[key]++;
}

void Pop()
{
    int x = st.top();
    st.pop();
    block[x/sqrN]--;
    table[x]--;
    printf("%d\n",x);//输出x
}

void peekMedian(int K)
{
    int sum = 0;
    int idx=0;
    while (sum+block[idx]<K)
    {
        sum+=block[idx++];
    }
    int n = idx*sqrN; //idx块的第一个数
    while( sum+table[n]<K )
    {
        sum+=table[n++];
    }
    printf("%d\n",n);
    
}



int main(int argc, char const *argv[])
{
    int x,query;
    //填充0
    memset(block,0,sizeof(block));
    memset(table,0,sizeof(table));
    char cmd[20];//命令
    scanf("%d",&query);//查询数目
    for(int i =0 ; i<query; i++ )
    {
        scanf("%s",cmd);
        if(strcmp(cmd,"Push") == 0)
        {
            scanf("%d",&x);//参数;
            Push(x);
        }
        else if(strcmp(cmd,"Pop")==0)
        {
            if(st.empty()==true)
            {
                printf("Invalid\n");
            }else
            {
                Pop();
            }
        }
        else{
            if(st.empty()==true)
            {
                printf("Invalid\n");
            }
            else
            {
                int K = st.size();
                if( K%2==1 ) K=(K+1)/2;
                else K=K/2;
                peekMedian(K);//输出中位数
            }
        }
    }
    
    return 0;
}
