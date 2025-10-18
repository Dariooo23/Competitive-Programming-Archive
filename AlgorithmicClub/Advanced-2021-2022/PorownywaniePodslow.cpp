//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
vector<LL> sHash(1000009);
vector<LL> pow27(1000009);
const LL podstawa=27;
const LL modulo=1e9+696969;
string s;

LL Hash(LL a, LL b)
{
    return (sHash[a]-((pow27[b-a+1]*sHash[b+1])%modulo)+modulo)%modulo;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>s;

    pow27[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        pow27[i]=(pow27[i-1]*podstawa)%modulo;
    }

    sHash[s.size()]=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        sHash[i]=(((sHash[i+1]*podstawa)%modulo)+(s[i]-'a'+1))%modulo;
    }

    int q;
    cin>>q;
    while(q--)
    {
        LL a,b,c,d,dl=1e18+9;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        dl=min(b-a,d-c);
        LL l=-1,r=dl,mid;
        while(l<r)
        {
            mid=(l+r+1)/2;
            if(Hash(a,a+mid)==Hash(c,c+mid))
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }

        l++;
        if(l<=dl)
        {
            if(s[a+l]<s[c+l])
            {
                cout<<"MNIEJSZY"<<endl;
            }
            else
            {
                cout<<"WIEKSZY"<<endl;
            }
        }
        else
        {
            if(b-a==d-c)
            {
                cout<<"ROWNY"<<endl;
            }
            else
            {
                if(b-a<d-c)
                {
                    cout<<"MNIEJSZY"<<endl;
                }
                else
                {
                    cout<<"WIEKSZY"<<endl;
                }
            }
        }

    }
    return 0;
}