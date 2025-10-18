//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
vector<int> monety1,monety2;
map<int,int> wartosc1,wartosc2;
int n,q,x;

void licz1() 
{
        int licz=0,reszta;
        for(int j=0;j<(1<<monety1.size());j++)
        {
            licz=0;
            reszta=0;
            for(int k=0;k<monety1.size();k++)
            {
                if((j&(1<<k))!=0)
                {
                    reszta=reszta+monety1[k];
                    //cout<<monety1[k]<<" ";
                    licz++;
                    if(wartosc1.find(reszta)!=wartosc1.end())
                    {
                        wartosc1[reszta]=min(wartosc1[reszta],licz);
                    }
                    else
                    {
                        wartosc1[reszta]=licz;
                    }
                }
            }
        }
}

void licz2() 
{
        int licz=0,reszta;
        for(int j=0;j<(1<<monety2.size());j++)
        {
            licz=0;
            reszta=0;
            for(int k=0;k<monety2.size();k++)
            {
                if((j&(1<<k))!=0)
                {
                    reszta=reszta+monety2[k];
                    //cout<<monety2[k]<<" ";
                    licz++;
                    if(wartosc2.find(reszta)!=wartosc2.end())
                    {
                        wartosc2[reszta]=min(wartosc2[reszta],licz);
                    }
                    else
                    {
                        wartosc2[reszta]=licz;
                    }
                }
            }
        }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    wartosc1[0]=0;
    wartosc2[0]=0;
    for(int i=0;i<(n/2);i++)
    {
        cin>>x;
        monety1.push_back(x);
    }
    for(int i=(n/2);i<n;i++)
    {
       cin>>x;
       monety2.push_back(x);
    }



    licz1();
    licz2();



    /*cout<<"MAPA PIERWSZA"<<endl;
    for (map<int,int>::iterator it=wartosc1.begin(); it!=wartosc1.end(); ++it)
    {
        cout << it->first << " => " << it->second << '\n';
    }
    cout<<"MAPA DRUGA"<<endl;
    for (map<int,int>::iterator it=wartosc2.begin(); it!=wartosc2.end(); ++it)
    {
        cout << it->first << " => " << it->second << '\n';
    }*/



    for(int i=0;i<q;i++)
    {
        int a,wynik=1e9+696969;
        cin>>a;
        for(map<int,int>::iterator it=wartosc1.begin(); it!=wartosc1.end();++it)
        {
            if(wartosc2.find(a-(it -> first))!=wartosc2.end())
            {
                wynik=min(wynik,wartosc1[it->first]+wartosc2[a-(it -> first)]);
                //cout<<it->first<<" "<<a-(it -> first)<<" "<<wartosc1[it->first]+wartosc2[a-(it -> first)]<<endl;
            }
        }
        if(wynik==1e9+696969)
        {
            cout<<"NIE"<<endl;
        }
        else
        {
            cout<<wynik<<endl;
        }
    }
    return 0;
}