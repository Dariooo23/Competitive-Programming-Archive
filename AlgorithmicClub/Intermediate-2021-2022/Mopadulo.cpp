//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;
const int M=1<<19;
int wynik=0;

vector<vector<int>> suma(2,vector<int> (M*2+1));
vector<pair<int,int>> tree(M*2+1);
vector<pair<int,int>> sufgdzie;
vector<int> wejscie;
vector<int> sumsuf;
vector<int> gdzie;

int query(int roznica, int indeks)
{
	if(tree[indeks].first+roznica<mod && tree[indeks].second+roznica<mod)
    {
		return suma[roznica%2][indeks];
	}
	if(tree[indeks].first+roznica>=mod && tree[indeks].second+roznica>=mod)
    {
		return suma[(roznica+1)%2][indeks];
	}

	return (query(roznica,indeks*2)+query(roznica,indeks*2+1))%mod;
}

void update(int indeks, int wartosc)
{
    indeks=indeks+M;
	bool pczynp=tree[indeks].first%2;

	while(indeks)
    {
		suma[pczynp][indeks]=(suma[pczynp][indeks]+wartosc)%mod;
		indeks=indeks/2;
	}
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    wejscie.resize(n+1);
    sumsuf.resize(n+2,0);
    sufgdzie.resize(n+1);
    gdzie.resize(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>wejscie[i];
    }
    for(int i=n;i>=1;i--)
    {
        sumsuf[i]=(sumsuf[i+1]+wejscie[i])%mod;
    }
    for(int i=0;i<=n;i++)
    {
        sufgdzie[i]={sumsuf[i+1],i};
    }

    sort(sufgdzie.begin(),sufgdzie.end());
    for(int i=0;i<=n;i++)
    {
        tree[i+M]={sufgdzie[i].first,sufgdzie[i].first};
        gdzie[sufgdzie[i].second]=i;
    }
    for(int i=M-1;i>=0;i--)
    {
        tree[i]={min(tree[i*2].first,tree[i*2+1].first),max(tree[i*2].second,tree[i*2+1].second)};
    }

    update(gdzie[0],1);
    for(int i=1;i<=n;i++)
    {
        wynik=query((mod-sumsuf[i+1])%mod,1);
        update(gdzie[i],wynik);
    }

    cout<<wynik;

    return 0;
}
 