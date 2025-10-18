#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
const long long int mod=1e9+7;

struct macierz{
    LL a,b,c,d;
};

macierz mno(macierz m1,macierz m2)
{
    macierz m3;
    m3.a=((m1.a*m2.a)+(m1.b*m2.c))%mod;
    m3.b=((m1.a*m2.b)+(m1.b*m2.d))%mod;
    m3.c=((m1.c*m2.a)+(m1.d*m2.c))%mod;
    m3.d=((m1.c*m2.b)+(m1.d*m2.d))%mod;

    return m3;
}

macierz pot(macierz m2, LL potega)
{
  macierz m3;
  if(potega==1)
  {
      return m2;
  }
  if(potega%2==1)
  {
      m3=pot(m2,potega/2);
      m3=mno(m2,mno(m3,m3));
  }
  else
  {
     m3=pot(m2,potega/2);
     m3=mno(m3,m3);
  }

  return m3;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    macierz m1,m2,m3;

    LL schody;
    cin>>schody;

    m1.a=3;       m2.a=3;   m3.a=0;
    m1.b=2;       m2.b=2;   m3.b=0;
    m1.c=1;       m2.c=1;   m3.c=0;
    m1.d=1;       m2.d=1;   m3.d=0;

    m3=mno(m1,pot(m2,schody));
    cout<<m3.d;
    return 0;
}