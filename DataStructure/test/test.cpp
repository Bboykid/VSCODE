#include<iostream>
using namespace std;
const int maxn = 10000;

void get_next(string mos, int *next)
{
    int i =0, j=-1;
    next[0] = -1;

    while ( i < mos.length())
    {
        if ( j==-1 || mos[i] == mos[j] )
        {
            i++;
            j++;
            next[i] = j;
        } 
        else
        {
            j = next[j];
        }
        
    }
    

}

int KMP(string str,string mos)
{
    int next[maxn];
    get_next(mos, next);
    
    int i = 0;
    int j = 0;

    while ( i < str.length() && j < mos.length())
    {
        if( j==-1 || str[i] == mos[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if( j >= mos.length())
        return i-mos.length();
    else 
        return -1;
    

}