//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

string k,lx,ly,dx,dy;
vector<vector<int>> kolejnosc={{0,7,8},{1,6,5},{2,3,4}};

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

string dodaj(string a, string b){
   if (a.length()>b.length())swap(a, b);
   string sum = "";

   int dlugosc1 = a.length();
   int dlugosc2 = b.length();
   int roznica = dlugosc2 - dlugosc1;
   int liczba = 0;
   int pom_suma;

   for (int i=dlugosc1-1;i>=0;i--) {
      pom_suma=((a[i]-'0')+(b[i+roznica]-'0')+liczba);
      sum.push_back(pom_suma%10+'0');
      liczba=pom_suma/10;
   }
   for(int i=roznica-1;i>=0;i--){
      pom_suma=((b[i]-'0')+liczba);
      sum.push_back(pom_suma%10+'0');
      liczba=pom_suma/10;
   }

   if(liczba)sum.push_back(liczba+'0');
   while(sum[sum.size()-1]=='0')sum.erase(sum.size()-1,1);
   reverse(sum.begin(), sum.end());
   return sum;
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

    while(roznica1[roznica1.size()-1]=='0')roznica1.erase(roznica1.size()-1,1);
    reverse(roznica1.begin(),roznica1.end());
    if(roznica1.size()==0){
        return "0";
    }else{
        return roznica1;
    }
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
        if(c[0]=='0')c="";
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

string modulo(string a,string b){
    return odejmij(a,mnozenie(dzielenie(a,b),b));
}

pair<string,string> transformacja(string x,string y,string bok,string wew_x,string wew_y){
    if((x[0]=='0' && y[0]=='2')||(x[0]=='2'&&y[0]=='0')||(x[0]=='2'&&y[0]=='1')||(x[0]=='2'&&y[0]=='2')){
        return {wew_x,wew_y};
    }
    if((x[0]=='0'&&y[0]=='1')||(x[0]=='1'&&y[0]=='1')){
        return {odejmij(odejmij(bok,wew_y),"1"),odejmij(odejmij(bok,wew_x),"1")};
    }
    if((x[0]=='0'&&y[0]=='0')||(x[0]=='1'&&y[0]=='0')){
        return {wew_y,wew_x};
    }
    if(x[0]=='1'&&y[0]=='2'){
        return {odejmij(odejmij(bok,wew_x),"1"),odejmij(odejmij(bok,wew_y),"1")};
    }

    return {"0","0"};
}

string odleglosc(string x,string y,string potega_k){
    if(potega_k=="0")return "0";

    string baz_x=dzielenie(x,potega_k);
    string baz_y=dzielenie(y,potega_k);

    string wew_x=modulo(x,potega_k);
    string wew_y=modulo(y,potega_k);

    pair<string,string> pomocnicza=transformacja(baz_x,baz_y,potega_k,wew_x,wew_y);

    string pom="";
    pom=pom+(char)(kolejnosc[(int)(baz_x[0]-'0')][(int)(baz_y[0]-'0')]+'0');
    return dodaj(odleglosc(pomocnicza.first,pomocnicza.second,dzielenie(potega_k,"3")),mnozenie(mnozenie(pom,potega_k),potega_k));
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>k>>lx>>ly>>dx>>dy;
    lx=odejmij(lx,"1");
    ly=odejmij(ly,"1");
    dx=odejmij(dx,"1");
    dy=odejmij(dy,"1");

    string wynik1="0",wynik2="0",potega_k="1";

    int pom1=0;
    for(int i=0;i<k.size();i++){
        pom1=pom1*10+(int)(k[i]-'0');
    }

    for(int i=1;i<pom1;i++){
        potega_k=mnozenie(potega_k,"3");
    }
    wynik1=odleglosc(lx,ly,potega_k);
    wynik2=odleglosc(dx,dy,potega_k);
    cout<<odejmij(wynik2,wynik1);

    
    return 0;
}
 