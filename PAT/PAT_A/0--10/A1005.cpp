#include<iostream>
#include<stack>
using namespace std;

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int
 * 
 * 此方法有误：题目要求N<10*10^100，不能这样做
 * 改用字符串读取N
 *  
 */

int main(int argc, char const *argv[])
{
    int N;
    int num=0;
    stack<int> st;
    cin>>N;
    int temp;
    string s;
    while(N!=0)
    {
        temp=N%10;//从低位到高位
        num+=temp;
        N=N/10;
    }
    if(num==0)
        st.push(0);
    while(num!=0)
    {
        temp=num%10;
        st.push(temp);
        num=num/10;
    }
    //OUTPUT

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
