//Karol Dziekan
#include<bits/stdc++.h>

using namespace std;

struct punkt
{
	long long int dlugosc;
	char litera;
};

vector<punkt> dp(3e5+9);

int main()
{
	std::ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	string slowo;
	cin >> slowo;
	long long int indeks=0,licznik=1;

	dp[indeks].litera=slowo[0];
	for(int i=1;i<=slowo.size();i++)
	{
		if(slowo[i]==dp[indeks].litera)
		{
			licznik++;
		}
		else
		{
			dp[indeks].dlugosc=licznik;

			indeks++;
			dp[indeks].litera=slowo[i];

			licznik=1;
		}
	}

	int flaga=0,poczatek=0,koniec=indeks-1;
	while(true)
	{
		if(poczatek==koniec)
		{
			break;
		}
		if((poczatek-koniec)==1)
		{
			break;
		}

		if(dp[poczatek].litera!=dp[koniec].litera)
		{
			flaga=1;
			break;
		}
		else 
		{
			if(dp[poczatek].dlugosc+dp[koniec].dlugosc<3)
			{
				flaga=1;
				break;
			}
		}

		poczatek++;
		koniec--;	
	}

	if(flaga==1)
	{
		cout<<0<<endl;
	}
	else
	{
		if(poczatek==koniec)
		{
			if(dp[poczatek].dlugosc>=2)
			{
				cout<<dp[poczatek].dlugosc+1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else
		{
			cout<<0<<endl;
		}
	}

}