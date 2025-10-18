//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

bool czy_mniejsza(string a, string b)
{
    int dlugosc1=a.size(),dlugosc2=b.size();
 
    if(dlugosc1<dlugosc2)return true;
    if(dlugosc2<dlugosc1)return false;
 
    for(int i=0;i<dlugosc1;i++){
        if(a[i]<b[i])return true;
        if(a[i]>b[i])return false;
    }
 
    return false;
}

string odejmij(string a, string b)
{
    if(czy_mniejsza(a,b))swap(a,b);

    string roznica1="";
    int dlugosc1=a.size(),dlugosc2=b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
 
    int liczba=0;
    for(int i=0; i<dlugosc2;i++){
        int roznica2=((a[i]-'0')-(b[i]-'0')-liczba);
        if(roznica2<0){
            roznica2=roznica2+10;
            liczba=1;
        }
        else{
            liczba=0;
        }

        roznica1.push_back(roznica2+'0');
    }

    for (int i=dlugosc2;i<dlugosc1;i++){
        int roznica2=((a[i]-'0')-liczba);
        if(roznica2<0){
            roznica2=roznica2+10;
            liczba=1;
        }
        else{
            liczba=0;
        }
 
        roznica1.push_back(roznica2+'0');
    }

    if(roznica1[roznica1.size()-1]=='0')roznica1.erase(roznica1.size()-1,roznica1.size()-1);
    reverse(roznica1.begin(),roznica1.end());
    return roznica1;
}

string dzielenie(string a, string b){
    string wynik="",c="";
    if(czy_mniejsza(a,b))return "0";

    int indeks1=0;
    while(indeks1<a.size()){
        c=c+a[indeks1];

        int ilosc=0;
        while(czy_mniejsza(c,b)==0){
            c=odejmij(c,b);
            ilosc++;
        }
        
        wynik=wynik+(char)(ilosc+'0');
        indeks1++;
    }

    int indeks2=0;
    while(wynik[indeks2]=='0' && indeks2!=wynik.size())indeks2++;
    wynik.erase(0,indeks2);

    if(wynik.size()==0){
        return "0";
    }else{
        return wynik;
    }
}

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

    int indeks=0;
    if(wyniki[wyniki.size()-1]!=0){
        indeks=wyniki.size()-1;
    }else{
        indeks=wyniki.size()-2;
    }

    string wynik="";
    for(int i=indeks;i>=0;i--){
        wynik=wynik+(char)(wyniki[i]+'0');
    }

    return wynik;
}

string modulo(string a,string b){
    return odejmij(a,mnozenie(dzielenie(a,b),b));
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string a,b;
    cin>>a>>b;
    cout<<modulo(a,b);


    return 0;
}
 