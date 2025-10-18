//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> klocki;
vector<long long int> prefiks_roznic;
vector<long long int> minimum_prefiks;
vector<long long int> maksimum_sufiks;

void solve(long long int k,long long int n){
    prefiks_roznic.resize(n+1);
    minimum_prefiks.resize(n+1);
    maksimum_sufiks.resize(n+1);

    prefiks_roznic[0]=0;
    for(int i=1;i<=n;i++){
        prefiks_roznic[i]=prefiks_roznic[i-1]+klocki[i]-k;
    }
    long long int wskaznik1=0,maksimum=1e18;
    for(int i=0;i<=n;i++){
        if(maksimum>prefiks_roznic[i]){
            minimum_prefiks[wskaznik1]=i;
            wskaznik1++;
            maksimum=prefiks_roznic[i];
        }
    }
    long long int wskaznik2=0,minimum=-1e18;
    for(int i=n;i>=0;i--){
        if(minimum<prefiks_roznic[i]){
            maksimum_sufiks[wskaznik2]=i;
            wskaznik2++;
            minimum=prefiks_roznic[i];
        }
    }

    long long int wynik=0,wskaznik3=wskaznik2-1;
    for(int i=0;i<wskaznik1;i++){
        while(wskaznik3>=0 && prefiks_roznic[maksimum_sufiks[wskaznik3]]>=prefiks_roznic[minimum_prefiks[i]]){
            wskaznik3--;
        }
        if(wskaznik3+1<wskaznik2 && prefiks_roznic[maksimum_sufiks[wskaznik3+1]]>=prefiks_roznic[minimum_prefiks[i]] && wynik<maksimum_sufiks[wskaznik3+1]-minimum_prefiks[i]){
            wynik=maksimum_sufiks[wskaznik3+1]-minimum_prefiks[i];
        }
    }

    cout<<wynik<<" ";
    prefiks_roznic.clear();
    minimum_prefiks.clear();
    maksimum_sufiks.clear();
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,q;
    cin>>n>>q;

    klocki.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>klocki[i];
    }

    while(q--){
        int k;
        cin>>k;
        solve(k,n);
    }
    return 0;
}
 