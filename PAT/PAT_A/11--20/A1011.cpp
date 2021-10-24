#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;



int main(int argc, char const *argv[])
{
    float g[3][3];
    int chose[3] ={0};
    int chose_num[3]={0};
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>g[i][j];
            if(g[i][j]>chose_num[i])
            {   
                 chose[i]=j;
                 chose_num[i] = g[i][j];
            }
        }
    }

    float sum=0;
    float w=1;
    for(int i=0; i<3;i++)
    {
        w *= g[i][chose[i]];
    }
    sum = (w*0.65 - 1)*2;

    for(int i=0;i<3;i++)
    {
        switch (chose[i])
        {
        case 0:
            cout<<'W';
            break;
        case 1:
            cout<<'T';
            break;
        case 2:
            cout<<'L';
            break;
        }
        cout<<' ';
    }
    printf("%.2f",sum);

    return 0;
}
