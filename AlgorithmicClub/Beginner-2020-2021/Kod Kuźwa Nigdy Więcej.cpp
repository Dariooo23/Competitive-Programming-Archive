#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int liczby[10];
int rozklad1[60000];
int rozklad2[60000];
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    string s;
    cin>>s;
    int mno=1,ind=0,przyklady=0,przykladyliczby=0,wynik2=1,wynik=0,nlp1=0;

    for (int i=(int)s.size()-1;i>=0;i--)
    {
if (s[i]=='*')
{
    mno=1;
    ind=ind+1;
}
else
{
    liczby[ind]=liczby[ind]+(s[i]-'0')*mno;
    mno=mno*10;
}

    }


 for (int i=0;i<ind+1;i++)
    {
        for (int  j=2;liczby[i]>1;j++)
{

    if(liczby[i]%j==0)
    {
        rozklad1[j-1]++;

        liczby[i]=liczby[i]/j;
if (nlp1<j)
{
    nlp1=j;
}
                j=1;
    }
}
    }

    for (int x=0;x<nlp1+1;x++)
            {
                if (rozklad1[x]!=0)
                {
                   wynik2=(rozklad1[x]+1)*wynik2;
                }

            }

cin>>przyklady;
for (int i=0;i<przyklady;i++)
{
    int NP=0;
    wynik=0;

    cin>>przykladyliczby;
    wynik=przykladyliczby;
    

for (int  j=2;przykladyliczby>1;j++)
{

    if(przykladyliczby%j==0)
    {
        rozklad2[j-1]++;
        if (rozklad2[j-1]>rozklad1[j-1])
        {
            NP=1;
            break;
        }
        przykladyliczby=przykladyliczby/j;
        j=1;
    }
}

       
wynik=wynik2+wynik;
if (NP==0)
{
    cout<<wynik<<endl;
}

 memset(rozklad2,0,60000*sizeof(int));

}

    return 0;
}