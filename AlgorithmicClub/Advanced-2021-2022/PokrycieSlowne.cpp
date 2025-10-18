//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const unsigned int podstawa=29;
const unsigned int podstawa2=37;
const unsigned int modulo=50159;
int pow29[5009];
int pow37[5009];
vector<unsigned int> HasheWzorcow(509);
vector<unsigned int> HasheWzorcow2(509);
vector<unsigned int> sHash;
vector<unsigned int> sHash2;
vector<string> wstepnewzorce(509);


unsigned int hashowanie(string s)
{
    unsigned int hash=0;

    for(char I : s)
    {
        hash=hash*podstawa;
        hash=hash+(I-'a'+1);
        hash=hash%modulo;
    }

    return hash;
}
unsigned int hashowanie2(string s)
{
    unsigned int hash=0;

    for(char I : s)
    {
        hash=hash*podstawa2;
        hash=hash+(I-'a'+1);
        hash=hash%modulo;
    }

    return hash;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin.tie(0);
    cout.tie(0);

    pow29[0]=1;
    for(int i=1;i<=5009;i++)
    {
        pow29[i]=(pow29[i-1]*podstawa)%modulo;
    }
    pow37[0]=1;
    for(int i=1;i<=5009;i++)
    {
        pow37[i]=(pow37[i-1]*podstawa2)%modulo;
    }


    string s;
    unsigned int n,m,rozmiar=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        wstepnewzorce[i]=a;
        HasheWzorcow[i]=hashowanie(a);
        HasheWzorcow2[i]=hashowanie2(a);
        rozmiar=rozmiar+a.size();
    }
    
    cin>>m;
    while(m--)
    {
        cin>>s;
        sHash.resize(s.size()+9);
        sHash2.resize(s.size()+9);


        sHash[0]=0;
        for(int i=1;i<=s.size();i++) 
        {
            sHash[i]=(podstawa*sHash[i-1]+(s[i-1]-'a'+1))%modulo;
        }
        sHash2[0]=0;
        for(int i=1;i<=s.size();i++) 
        {
            sHash2[i]=(podstawa2*sHash2[i-1]+(s[i-1]-'a'+1))%modulo;
        }

        vector<pair<unsigned int,unsigned int>> dp(s.size()+9,{-1,-1});
        dp[0]={0,0};
        for(int i=0;i<=s.size();i++)
        {
            if(dp[i].first!=-1)
            {
                for(int j=0;j<n;j++)
                {
                    if(wstepnewzorce[j].size()+i<=s.size())
                    {
                        if(sHash[i+wstepnewzorce[j].size()]==(HasheWzorcow[j]+(dp[i].first*pow29[wstepnewzorce[j].size()])%modulo)%modulo)
                        {
                            if(sHash2[i+wstepnewzorce[j].size()]==(HasheWzorcow2[j]+(dp[i].second*pow37[wstepnewzorce[j].size()])%modulo)%modulo)
                            {
                                dp[i+wstepnewzorce[j].size()].first=sHash[i+wstepnewzorce[j].size()];
                                dp[i+wstepnewzorce[j].size()].second=sHash2[i+wstepnewzorce[j].size()];
                            }
                        }
                    }
                }
            }
        }

        if(dp[s.size()].first!=-1)
        {
            cout<<"TAK"<<'\n';
        }
        else
        {
            cout<<"NIE"<<'\n';
        }
        dp.clear();
    }
    return 0;
}