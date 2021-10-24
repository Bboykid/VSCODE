#include<cstdio>
#include<string>

const int maxn = 100010;

struct node
{
    char data;
    int next;
    bool flag;
}nodes[maxn];


int main(int argc, char const *argv[])
{

    for (int i = 0; i < maxn; i++)
    {
        nodes[i].flag = false;
    }

    int s1,s2,N;//字符串s1,s2的首地址,N为节点数量

    scanf("%d%d%d",&s1,&s2,&N);

    int address,next;//当前地址和下一节点的地址
    char c;//

    //input data
    for( int i = 0 ; i < N; i++)
    {
        scanf("%d %c %d",&address,&c,&next);
        nodes[address].data = c;
        nodes[address].next = next;
    }
    //finish input
    //the data is stored in the array--nodes

    //traverse the str1, mark the node visited

    address = s1;
    while (address != -1)
    {
        nodes[address].flag = true;
        address = nodes[address].next;
    }

    address = s2;
    while (address != -1)
    {
       if(nodes[address].flag == true)
       {
           break;
       }
        address = nodes[address].next;
    }
    
    if (address != -1)
    {
        printf("%d",address);
    }
    else
    {
        printf("-1");
    }
    

    return 0;
}

