#include <stdio.h>
#include <stdlib.h>

int mSIZE=3;                  
int pSIZE=20;                      
static int memery[10]={0};      
static int page[100]={0};     
static int temp[100][10]={0};  

void FIFO();
void LRU();
void OPT();

void print(unsigned int t);

int main()
{
    int i,k,code;
    puts("请依次输入页面号引用串(用空格隔开)：");
    for(i=0;i<pSIZE;i++)
        scanf("%1d",&page[i]);
    system("cls");
    do{
        puts("\n 输入的页面号引用串为：");
        for(k=0;k<=(pSIZE-1)/20;k++)
        {
            for(i=20*k;(i<pSIZE)&&(i<20*(k+1));i++)
            {
                if(((i+1)%20==0)||(((i+1)%20)&&(i==pSIZE-1)))
                    printf("%d\n",page[i]);
                else
                    printf("%d   ",page[i]);
            }
        }
        
        
        printf("*\t1.最佳置换算法(OPT)                     *\n");
        printf("*\t2.先进先出算法(FIFO)                    *\n");
        printf("*\t3.最近最久未使用(LRU)                   *\n");
        printf("*\t4.退出                                  *\n");
        printf("选择操作：[ ]\b\b");
        scanf("%d",&code);
        printf("\n");
        switch(code)
        {
        case 1:
            OPT();
            break;
        case 2:
            FIFO();
            break;
        case 3:
            LRU();
            break;
        case 4:
            system("cls");
            exit(0);
        default:
            printf("\n输入错误，请重新输入!!!\n\n\n");
        }
    }while (code!=4);
    getchar();
}
 
void print(unsigned int t)
{
    int i,j,k,l;
    int flag;
    for(k=0;k<=(pSIZE-1)/20;k++)
    {
        for(i=20*k;(i<pSIZE)&&(i<20*(k+1));i++)
        {
            if(((i+1)%20==0)||(((i+1)%20)&&(i==pSIZE-1)))
                printf("%d\n",page[i]);
            else
                printf("%d   ",page[i]);
        }
        for(j=0;j<mSIZE;j++)
        {
            for(i=20*k;(i<mSIZE+20*k)&&(i<pSIZE);i++)
            {
                if(i>=j)
                    printf(" |%d|",temp[i][j]);
                else
                    printf(" | |");
            }
            for(i=mSIZE+20*k;(i<pSIZE)&&(i<20*(k+1));i++)
            {
                for(flag=0,l=0;l<mSIZE;l++)
                    if(temp[i][l]==temp[i-1][l])
                        flag++;
                if(flag==mSIZE)         
                    printf("    ");
                else
                    printf(" |%d|",temp[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n------------------------------------------\n");
    printf("  缺页次数：%d\t\t",t+mSIZE);
    printf("缺页率：%d/%d\n",t+mSIZE,pSIZE);
    printf("  置换次数：%d\t\t",t);
    printf("访问命中率：%d%%\n",(pSIZE-(t+mSIZE))*100/pSIZE);
    printf("------------------------------------------\n");   
}
 
 

void FIFO()
{
    int memery[10]={0};
    int time[10]={0};   
    int i,j,k,m;
    int max=0;          
    int count=0;        
   
    for(i=0;i<mSIZE;i++)
    {
        memery[i]=page[i];
        time[i]=i;
        for(j=0;j<mSIZE;j++)
            temp[i][j]=memery[j];
    }
    for(i=mSIZE;i<pSIZE;i++)
    {
        
        for(j=0,k=0;j<mSIZE;j++)
        {
            if(memery[j]!=page[i])
                k++;
        }
        if(k==mSIZE)        
        {
            count++;
            
            max=time[0]<time[1]?0:1;
            for(m=2;m<mSIZE;m++)
                if(time[m]<time[max])
                    max=m;
            memery[max]=page[i];
            time[max]=i;    
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
        else
        {
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
    }
    print(count);
}
 

void LRU()
{
    int memery[10]={0};
    int flag[10]={0};   
    int i,j,k,m;
    int max=0;          
    int count=0;        
   
    for(i=0;i<mSIZE;i++)
    {
        memery[i]=page[i];
        flag[i]=i;
        for(j=0;j<mSIZE;j++)
            temp[i][j]=memery[j];
    }
    for(i=mSIZE;i<pSIZE;i++)
    {
        
        for(j=0,k=0;j<mSIZE;j++)
        {
            if(memery[j]!=page[i])
                k++;
            else
                flag[j]=i; 
        }
        if(k==mSIZE)        
        {
            count++;
          
            max=flag[0]<flag[1]?0:1;
            for(m=2;m<mSIZE;m++)
                if(flag[m]<flag[max])
                    max=m;
            memery[max]=page[i];
            flag[max]=i;   
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
        else
        {
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
    }
    print(count);
}
 

void OPT()
{
    int memery[10]={0};
    int next[10]={0};   
    int i,j,k,l,m;
    int max;            
    int count=0;        
    
    for(i=0;i<mSIZE;i++)
    {
        memery[i]=page[i];
        for(j=0;j<mSIZE;j++)
            temp[i][j]=memery[j];
    }
    for(i=mSIZE;i<pSIZE;i++)
    {
        
        for(j=0,k=0;j<mSIZE;j++)
        {
            if(memery[j]!=page[i])
                k++;
        }
        if(k==mSIZE)    
        {
            count++;
            
            for(m=0;m<mSIZE;m++)
            {
                for(l=i+1;l<pSIZE;l++)
                    if(memery[m]==page[l])
                        break;
                next[m]=l;
            }
            
            max=next[0]>=next[1]?0:1;
            for(m=2;m<mSIZE;m++)
                if(next[m]>next[max])
                    max=m;
            
            memery[max]=page[i];
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
        else {
            for(j=0;j<mSIZE;j++)
                temp[i][j]=memery[j];
        }
    }
    print(count);
}
