//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string mnozenie(string liczba1, string liczba2)
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

    string wynik="";
    for(int i=0;i<wyniki.size();i++){
        wynik=wynik+(char)(wyniki[i]+'0');
    }

    while(wynik[wynik.size()-1]=='0')wynik.erase(wynik.size()-1,1);

    reverse(wynik.begin(),wynik.end());
    if(wynik.size()==0){
        return "0";
    }else{
        return wynik;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    cout<<mnozenie(a,b);
}