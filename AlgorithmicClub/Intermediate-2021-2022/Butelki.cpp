//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;

int pojemnosc_a,pojemnosc_b,pojemnosc_c,suma,stan_a,stan_b,stan_c,stan_a1,stan_b1;
queue<pair<int,pair<int,int>>> q;
vector<int> wyniki(1e6+9,-1);
set<pair<int,int>> visited;

void przelej(int poczatek, int koniec, int pojemnosc_y)
{
	stan_b1=min(poczatek+koniec,pojemnosc_y);
	stan_a1=poczatek+koniec-stan_b1;
    
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>pojemnosc_a>>pojemnosc_b>>pojemnosc_c;
	cin>>stan_a>>stan_b>>stan_c;
	suma=stan_a+stan_b+stan_c;

	q.push({0,{stan_a,stan_b}});
	while(!q.empty())
	{
		pair<int,pair<int,int>> p=q.front();
		q.pop();

		if(visited.find(p.second)!=visited.end())
        {
            continue;
        }

		visited.insert(p.second);
		stan_a=p.second.first;
		stan_b=p.second.second;
		stan_c=suma-stan_a-stan_b;

		if(wyniki[stan_a]==-1)
        {
            wyniki[stan_a]=p.first;
        }
		if(wyniki[stan_b]==-1)
        {
            wyniki[stan_b]=p.first;
        }
		if(wyniki[stan_c]==-1)
        {
            wyniki[stan_c]=p.first;
        }

		przelej(stan_a,stan_b,pojemnosc_b);
		if(visited.find({stan_a1,stan_b1})==visited.end()) 
        {
            q.push({p.first+1,{stan_a1,stan_b1}});
        }
		przelej(stan_a,stan_c,pojemnosc_c);
		if(visited.find({stan_a1,stan_b})==visited.end())
        {
            q.push({p.first+1,{stan_a1,stan_b}});
        }
		przelej(stan_b,stan_a,pojemnosc_a);
		if(visited.find({stan_b1,stan_a1})==visited.end())
        {
            q.push({p.first+1,{stan_b1,stan_a1}});
        }
		przelej(stan_b,stan_c,pojemnosc_c);
		if(visited.find({stan_a,stan_a1})==visited.end())
        {
            q.push({p.first+1,{stan_a,stan_a1}});
        }
		przelej(stan_c,stan_a,pojemnosc_a);
		if(visited.find({stan_b1,stan_b})==visited.end())
        {
            q.push({p.first+1,{stan_b1,stan_b}});
        }
		przelej(stan_c,stan_b,pojemnosc_b);
		if(visited.find({stan_a,stan_b1})==visited.end())
        {
            q.push({p.first+1,{stan_a,stan_b1}});
        }
	}

	for(int i=0; i<=pojemnosc_c; i++)
    {
        cout<<wyniki[i]<<" ";
    }

	return 0;
}