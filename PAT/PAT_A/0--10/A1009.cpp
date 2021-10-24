    #include<iostream>
    #include<map>
    #include<vector>
    using namespace std;


    int main(int argc, char const *argv[])
    {
        int K;
        int N;//N为指数
        double x;//x为系数
        map<int,float> M;
        map<int,float> a;//保存多项式a
        map<int,float> b;//保存多项式b

        //输入第一个多项式
        cin>>K;
        while(K--)
        {
            cin>>N>>x;
            a[N] += x;
        }

        //输入第二个多项式
        cin>>K;
        while(K--)
        {
            cin>>N>>x;
            for(auto it=a.begin(); it!=a.end(); it++)
            {
                int tempN= N+it->first;
                int tempx = x+it->second;
                M[tempN] += tempx;
                
            }
        }


        cout<<M.size();
        for(auto it=M.end(); it!=M.begin();)
        {
            --it;
             printf(" %d %.1f",it->first,it->second);
        }


        return 0;
    }
