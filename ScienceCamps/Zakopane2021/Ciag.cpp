#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
const int mod=1000000007;

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL a1,a2,x,y;
    cin>>a1>>a2>>x>>y;
    macierz m1,m2,m3;

    int testy;
    cin>>testy;
    for(int i=0;i<testy;i++)
    {
        LL dzien;
        cin>>dzien;
        m1.a=(x*a2+y*a1)%mod;  m2.a=x;   m3.a=0;
        m1.b=a2;               m2.b=1;   m3.b=0;
        m1.c=a2;               m2.c=y;   m3.c=0;
        m1.d=a1;               m2.d=0;   m3.d=0;
        if(dzien==1)
        {
            cout<<m1.d<<endl;
        }
        else
        {
          m3=mno(m1,pot(m2,dzien-1));
          cout<<m3.d<<endl;
        }

    }

    return 0;
}