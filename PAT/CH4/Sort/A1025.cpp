/**
 * @file A1025.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-22
 * 
 * @copyright Copyright (c) 2021
 * 
 *
 * 
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
    /* data */
    char id[15];
    int score;
    int location;
    int rank;
    int local_rank;
}Students[30010];

bool compare(Student A, Student B)
{
    if( A.score != B.score)
        return (A.score > B.score);
    else
        return (strcmp(A.id,B.id) < 0);
}

int main(int argc, char const *argv[])
{
    
    int location_count;//考场数量
    int N;//每个考场的人数
    int num = 0;//total numner of students
   scanf("%d",&location_count);
   for(int i =1; i<=location_count; i++)
   {
       scanf("%d", &N);
       for(int j = 0; j < N; j++)
       {
           //TODO input
            scanf("%s %d",Students[num].id, &Students[num].score);
            Students[num].location = i;
            num++;
       }
       int start = num -N;
        sort(Students+start, Students + num, compare);

        Students[start].local_rank = 1;
        for(int k = start + 1; k < num ;k++)
        {
            if(Students[k].score == Students[k-1].score)
                Students[k].local_rank = Students[k-1].local_rank;
            else
                Students[k].local_rank = k - start + 1;
        }
   }
   sort(Students,Students+num,compare); 
   cout<<num<<endl;
    Students[0].rank = 1;
    
    for(int i = 1 ;i < num ;i++)
    {
        if(Students[i].score == Students[i-1].score )
             Students[i].rank = Students[i-1].rank;
        else
            Students[i].rank = i+1;
    }
    for(int i = 0 ; i< num ;i++)
    {
         cout<<Students[i].id<<" "<<Students[i].rank<<" "<<Students[i].location<<" "<<Students[i].local_rank<<endl;
    }

    return 0;
}
