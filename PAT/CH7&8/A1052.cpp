#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Node {
    int address;
    int data;
    int next;
    bool flag;
}node[maxn];

bool cmp(Node A, Node B)
{
    if( A.flag == false || B.flag == false)
    {
        return A.flag > B.flag;
    }
    else   
        return A.data < B.data;
}

int main(int argc, char const *argv[])
{
    for( int i=0 ; i < maxn ; i++)
    {
        node[i].flag = false;
    }

    //input
    int N,begin;
    scanf("%d%d",&N,&begin);
    int address,data,next;
    for (int  i = 0; i < N; i++)
    {
        scanf("%d%d%d",&address,&data,&next);

        node[address].address = address;
        node[address].data = data;
        node[address].next = next; 
        // node[address].flag = true;  
    }
    
    int count = 0;
    int p = begin;
    while (p != -1)
    {   
        node[p].flag = true;
        count++;
        p = node[p].next;
    }

    if(count == 0)
        printf("0 -1");
    else
    {
            sort(node,node + maxn, cmp);
            //防止-1被05d化，提前判断
            printf( "%d %05d\n",count,node[0].address);
            for(int i = 0; i<count ; i++)
            {
                if( i != count - 1)
                {
                    printf( "%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
                }
                else
                {
                    printf( "%05d %d -1\n",node[i].address,node[i].data);
                        
                }
            }
    }


    return 0;
}
