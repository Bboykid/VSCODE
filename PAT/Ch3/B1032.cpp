#include<iostream>
using namespace std;
#define MaxNum 100010

int main(int argc, char const *argv[])
{
    int N;
    int school_score[MaxNum] = {0};
    int school_id,score;
    cin>>N;
    for (size_t i = 0; i < N; i++)
    {
        /* code */
        cin>>school_id>>score;
        school_score[school_id]+=score;
    }
    int Max_id = 1,Max_score = -1;
    for (int i = 1; i <= N; i++)
    {
        /* code */
        if(school_score[i]  > Max_score)
        {
            Max_score = school_score[i];
            Max_id = i;
        }
    }
    cout<<Max_id<<" "<<Max_score<<endl;
    
    return 0;
}
