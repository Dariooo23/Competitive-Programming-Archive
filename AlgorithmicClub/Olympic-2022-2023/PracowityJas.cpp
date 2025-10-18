//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const long long int modulo=1e9+7;
const long long int m=1<<20;
vector<int> tablica;

long long n,wynik1=0,wynik2=0;
int main(){
	ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	cin>>n;
    tablica.resize(m*2);

	for(int i=0;i<n;i++){
        long long int liczba1=0,liczba2=0,liczba3=0,pomoc=0;
		cin>>liczba1;

		liczba2=liczba1+m;
		while(liczba2>0){
			tablica[liczba2]++;
			liczba2/=2;
		}

		liczba2=liczba1+m;
		while(liczba2>0){
			if(liczba2%2==0){
				liczba3=liczba3+tablica[liczba2];
				liczba2=(liczba2-1)/2;
			}else{
                liczba2/=2;
            }
		}

        pomoc=wynik2;
		wynik2=(wynik2*(n-i-1)+liczba1-liczba3)%modulo;
		wynik1=(wynik1+wynik2*((n-i+1)/2))%modulo;
		wynik2=(wynik2+pomoc)%modulo;
	}

	cout<<wynik1<<endl;
    return 0;
}

