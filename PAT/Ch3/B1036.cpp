#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int row,col;
    char ch;
    cin>>col;
    cin>>ch;
    if(col % 2 == 1)
        row = (col+1)/2;
    else
        row =col/2;
    
    for(int i = 0 ; i< row ; i++)
    {
        if(i==0 || i== row -1)
        {
            for (size_t i = 0; i < col; i++)
            {
                /* code */
                cout<<ch;
            }
        }
        else
        {
            cout<<ch;
            for (size_t i = 0; i < col - 2; i++)
            {
                /* code */
                cout<<" ";
            }
            cout<<ch;
        }
        cout<<endl;
    }

    return 0;
}
