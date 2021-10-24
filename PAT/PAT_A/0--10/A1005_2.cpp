#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string num;
    stack<int> st;
    cin>>num;
    int sum=0;
    for(auto it=num.begin();it!=num.end();it++)
    {
        sum+=(int)(*it-'0');
    }
    int temp;

    if(sum==0)
        st.push(0);
    while(sum!=0)
    {
        temp = sum%10;
        st.push(temp);
        sum = sum/10;
    }

    string s;
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        switch (temp)
        {
        case 0:
            s="zero";
            break;
        case 1:
            s="one";
            break;
        case 2:
            s="two";
            break;
        case 3:
            s="three";
            break;
        case 4:
            s="four";
            break;
        case 5:
            s="five";
            break;
        case 6:
            s="six";
            break;
        case 7:
            s="seven";
            break;
        case 8:
            s="eight";
            break;
        case 9:
            s="nine";
            break;       
        }
        cout<<s;
        if(st.size()>0)
            cout<<' ';
    }



    return 0;
}
