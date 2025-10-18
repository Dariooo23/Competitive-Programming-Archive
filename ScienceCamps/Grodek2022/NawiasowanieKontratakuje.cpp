//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool solve()
{
        int wynik=0;
        bool dziala=1;
    
        string nawiasy;
        cin>>nawiasy;

        if(nawiasy.size()%2==1)
        {
            return 0;
        }

        deque<int> pytania;
        pytania.clear();

        for(int i=0;i<nawiasy.size();i++)
        {
            if(nawiasy[i]=='?')
            {
                pytania.push_back(i);
            }
            if(nawiasy[i]=='(')
            {
                wynik++;
            }
            if(nawiasy[i]==')')
            {
                wynik--;
                if(wynik<0)
                {
                    if(pytania.size()==0)
                    {
                        return 0;
                    }
                    else
                    {
                        wynik++;
                        nawiasy[pytania.front()]='(';
                        pytania.pop_front();
                    }
                }
            }
        }

        for(int i=0;i<wynik;i++)
        {
            if(pytania.size()==0)
            {
                return 0;
            }
            nawiasy[pytania.back()]=')';
            pytania.pop_back();
        }
        
        wynik=0;
        for(int i=0;i<nawiasy.size();i++)
        {
            if(nawiasy[i]=='(')
            {
                wynik++;
            }
            if(nawiasy[i]==')')
            {
                wynik--;
                if(wynik<0)
                {
                    return 0;
                }
            }
        }

        if(wynik==0 && pytania.size()%2==0 && dziala==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }

}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 
    
    int testy;
    cin>>testy;

    while(testy--)
    {
        if(solve()==1)
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
    return 0;
}
 