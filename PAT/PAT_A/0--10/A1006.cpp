/**
 * @file A1006.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 * 
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct record
{
    char ID[15];
    char SignIn[8];
    char SignOut[8];   
}record;

vector<record> vec;


int main(int argc, char const *argv[])
{
    int M;
    cin>>M;

    string earlist_signin = "999",last_signout="000";
    string earlist,last; 
    string id,in,out;

    while (M--)
    {
        cin>>id>>in>>out;
        if(in<earlist_signin)
        {
            earlist_signin = in;
            earlist = id;
        }
        if(out>last_signout)
        {
            last_signout = out;
            last = id;
        }

    }
    cout<<earlist<<' '<<last;

   


    return 0;
}
