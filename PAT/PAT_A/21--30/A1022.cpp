#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

unordered_map<string,set<string>> MAP[6];

int main()
{
    int N;
    cin>>N;
    getchar();
    while(N--)
    {
        string ID,title,author,key,publisher,year;
        getline(cin,ID);
        getline(cin,title);
        MAP[1][title].insert(ID);

        getline(cin,author);
        MAP[2][author].insert(ID);

        //keyword 
        do{
            cin>>key;
            MAP[3][key].insert(ID);
        } while(getchar() == ' ');

        getline(cin,publisher);
        MAP[4][publisher].insert(ID);
        
        getline(cin,year);
        MAP[5][year].insert(ID);

    }

    //search
    int M;
    cin>>M;
    while(M--)
    {
        int i;
        string word;
        cin>>i;
        getchar();
        getchar();
        getline(cin,word);
        cout<<i<<": "<<word<<endl;
        if(MAP[i][word].size())
        {
            for(string Str : MAP[i][word])
            {
                cout<<Str<<endl;
            }
        }
        else
        {
            cout<<"Not Found"<<endl;
        }
    }

}