//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct node{
	node *lewo=0,*prawo=0,*poprzedni=0;
	long long inwersje=0,przedzial=0,ilosc=0;
};

vector<node*> punkty(300000); 
vector<long long int> tree(300000,0);
long long int licznik=0,n;

long long int query(long long int indeks){
	long long int wynik=0;

	while(indeks>0){
		wynik=wynik+tree[indeks];
		indeks=indeks-(indeks&(-indeks));
	}

	return wynik;
}

void update(long long int indeks,long long int wartosc){
	while(indeks<=n){
		tree[indeks]=tree[indeks]+wartosc;
		indeks=indeks+(indeks&(-indeks));
	}
	return;
}

void wczytywanie(node *punkt){
	long long int lisc;
	cin>>lisc;

	if(lisc!=0){
		punkt->przedzial=1;
		licznik++;
		punkt->ilosc=licznik;
		punkty[lisc-1]=punkt;
	}else{
		punkt->lewo=new node; 
		punkt->prawo=new node;

		wczytywanie(punkt->lewo); 
		wczytywanie(punkt->prawo);

		punkt->ilosc=punkt->lewo->ilosc;
		punkt->przedzial=punkt->lewo->przedzial+punkt->prawo->przedzial;
	}
}

void stworz_drzewo(node *punkt,node *rodzic,int strona){
	if(rodzic!=0){
		if(strona){
			punkt->poprzedni=rodzic;
		}else{
			punkt->poprzedni=rodzic->poprzedni;
		}
	}
	if(punkt->przedzial==1){
		return;
	}
	if((punkt->prawo->przedzial)>(punkt->lewo->przedzial)){
		swap(punkt->lewo,punkt->prawo);
	}

	stworz_drzewo(punkt->lewo,punkt,0); 
	stworz_drzewo(punkt->prawo,punkt,1);
	return;
}

long long int solve(node *punkt){
	if(punkt->przedzial==1){
		return 0;
	}

	long long int inwersje=punkt->inwersje;
	long long int odwrotnosc=(punkt->lewo->przedzial)*(punkt->prawo->przedzial)-inwersje;

	long long int lewo=solve(punkt->lewo);
	long long int prawo=solve(punkt->prawo);

	return min(inwersje,odwrotnosc)+lewo+prawo;
}

int main(){
	std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

	cin>>n;

	node *punkt;
	node *korzen=new node;

	wczytywanie(korzen);
	stworz_drzewo(korzen,0,0);

	for(int i=1;i<=n;i++){
		update(i,1);
	}

	for(int i=0;i<n;i++){
		punkt=punkty[i]->poprzedni;

		while(punkt!=0){
			punkt->inwersje=punkt->inwersje+query((punkt->lewo->ilosc)+(punkt->lewo->przedzial-1))-query(punkt->lewo->ilosc-1);
			punkt=punkt->poprzedni;
		}

		update(punkty[i]->ilosc,-1);
	}

	cout<<solve(korzen);
	return 0;
}