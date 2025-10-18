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

    while(roznica1[roznica1.size()-1]=='0')roznica1.erase(roznica1.size()-1,1);
    reverse(roznica1.begin(),roznica1.end());
    if(roznica1.size()==0){
        return "0";
    }else{
        return roznica1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string a,b;
    cin>>a>>b;
    cout<<odejmij(a,b);

    return 0;
}
 