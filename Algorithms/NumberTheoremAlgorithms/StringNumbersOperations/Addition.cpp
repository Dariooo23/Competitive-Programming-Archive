//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string a,b;
    cin>>a>>b;
    cout<<dodaj(a,b);

    return 0;
}
 