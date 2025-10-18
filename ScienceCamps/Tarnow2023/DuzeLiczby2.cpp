//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void mnozenie(string liczba1, string liczba2)
{
    const int dlugosc1=liczba1.size();
    const int dlugosc2=liczba2.size();
    if(dlugosc1==0 || dlugosc2==0){
        cout<<"0";
        exit(0);
    }
    vector<int> wyniki(dlugosc1+dlugosc2,0);
 
    int indeks1=0,indeks2=0,cyfra1,cyfra2,sum,przenies;
    for(int i=dlugosc1-1;i>=0;i--){
        przenies=0;
        cyfra1=liczba1[i]-'0';
        indeks2=0;
                 
        for (int j=dlugosc2-1;j>=0;j--){
            cyfra2=liczba2[j]-'0';
            sum=cyfra1*cyfra2+wyniki[indeks1+indeks2]+przenies;
            przenies=sum/10;
            wyniki[indeks1+indeks2]=sum%10;
            indeks2++;
        }
 
        if(przenies>0)wyniki[indeks1+indeks2]=wyniki[indeks1+indeks2]+przenies;
        indeks1++;
    }

    int indeks=0;
    if(wyniki[wyniki.size()-1]!=0){
        indeks=wyniki.size()-1;
    }else{
        indeks=wyniki.size()-2;
    }
    for(int i=indeks;i>=0;i--){
        cout<<wyniki[i];
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string liczba1,liczba2="",liczba3="";
    cin>>liczba1;

    int suma=0;
    for(int i=0;i<liczba1.size();i++){
        suma=suma+(liczba1[i]-'0');
    }
    while(suma>0){
        liczba2.push_back((char)('0'+suma%10));
        suma=suma/10;
    }
    for(int i=0;i<liczba1.size();i++){
        liczba3.push_back('1');
    }

    reverse(liczba2.begin(),liczba2.end());
    mnozenie(liczba3,liczba2);
}