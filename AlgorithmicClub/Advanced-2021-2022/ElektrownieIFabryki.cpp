#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1<<20);
vector<int> W(1<<20);
vector<int> P(1<<20);
vector<long long int> Drzewo((1<<21)+9);
vector<long long int> So(1<<20);
pair<long long int,long long int> S[1<<20];


long long int szukaj(int l, int r, int ll, int rr, int w)
{
    if(ll>r || rr<l)
    {
        return 0;
    }

    if(ll>=l&&rr<=r)
    {
        return Drzewo[w];
    }

    return max(szukaj(l,r,ll,(ll+rr)/2,w*2),szukaj(l,r,(ll+rr)/2+1,rr,w*2+1));
}


void dodaj(long long int Dp, int w)
{
    if(w==0)
    {
        return;
    }

    Drzewo[w]=max(Dp,Drzewo[w]);
    dodaj(Dp,w/2);
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>W[i];
        So[i]=So[i-1]+W[i];
        S[i].first=S[i-1].first+W[i];
        S[i].second=i;
    }

    if(So[n]<0)
    {
        cout<<-1;
        exit(0);
    }

    sort(S+1,S+n+1);
    long long int x=1e18+9;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(S[i].first!=x)
        {
            x=S[i].first;
            p++;
        }
        P[S[i].second]=p;
    }

    for(int i=1;i<=n;i++)
    {
        if(So[i]>=0)
        {
            dp[i]=szukaj(1,P[i],1,1<<20,1)+1;
            dodaj(dp[i],(1<<20)+P[i]-1);
        }
    }
    cout<<n-dp[n];
}