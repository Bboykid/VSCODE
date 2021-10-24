#include<iostream>
#include<vector>
using namespace std;

int radix=13;


int R,G,B;


int main()
{
    cin>>R>>G>>B;
    int r1,r2,g1,g2,b1,b2;
    r1=R/radix;
    r2=R%radix;
    g1=G/radix;
    g2=G%radix;
    b1=B/radix;
    b2=B%radix;
    vector<int> v;
    v.emplace_back(r1);
    v.emplace_back(r2);
    v.emplace_back(g1);
    v.emplace_back(g2);
    v.emplace_back(b1);
    v.emplace_back(b2);
    cout<<"#";
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=9)
        {
            cout<<v[i];
        }
        else{
            char c= 'A'+(v[i]-10);
            cout<<c;
        }
    }


    return 0;
}



