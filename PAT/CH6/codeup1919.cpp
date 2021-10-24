#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

typedef struct node
{
    double num;//操作数
    char op;//操作符
    bool flag;// true表示操作数 false表示操作符
}node;


string str;
stack<node> s;
queue<node> q;
map<char,int> op;


// stack<double> num_stack;
// stack<char> op_stack;

//转换成逆波兰表达式在计算
void Change(string str)
{
    double num;
    node temp;
    for (int i = 0; i < str.length();)
    {
        if( str[i] >='0' && str[i] <= '9')
        {
            temp.flag =true;
            temp.num = str[i++] - '0';
            while( i<str.length() && str[i] >='0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i]-'0');
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag = false;
            //当前优先级高
            while (!s.empty() && op[str[i]] <= op[s.top().op] )
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }  
    }
    while( !s.empty() )
    {
        q.push(s.top());
        s.pop();
    }

}

double Calculate()
{
    double temp1,temp2;
    node cur,temp;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if( cur.flag == true ) s.push(cur);
        else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+') temp.num = temp1 + temp2;
            else if(cur.op == '-') temp.num = temp1 -temp2;
            else if(cur.op == '*') temp.num = temp1 *temp2;
            else temp.num = temp1 /temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(int argc, char const *argv[])
{
    op['+'] = op['-'] =1;
    op['*'] = op['/'] =2;
    return 0;
}


//双栈法
/**
void change(string str)
{

    for (int i = 0; i < str.length();)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {   
            double temp = str[i]-'0';
            i++;
            while ( i < str.length() && str[i] >='0' && str[i] <='9')
            {
                temp = temp * 10 + (str[i] - '0');
                i++;
            }
            num_stack.push(temp);
        }
        else
        {
            char op = str[i];
            if (op_stack.empty())
            {
                op_stack.push(op);
            }
            else
            {
                switch (str[i])
                {
                case '+':
                    
                    break;
            
                default:
                    break;
            }
            }
            
        }        
    }
    
}
**/