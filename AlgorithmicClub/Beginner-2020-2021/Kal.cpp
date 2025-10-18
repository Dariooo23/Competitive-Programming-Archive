#include <iostream>

using namespace std;

int main()
{
    char a;
    int b,c,wynik=0;
    while (cin>>a>>b>>c)
    {
        if (a=='+')
        {
            wynik=b+c;
            cout<<wynik<<endl;
            wynik=0;
        }
        if (a=='-')
        {
            wynik=b-c;
            cout<<wynik<<endl;
            wynik=0;
        }if (a=='*')
        {
            wynik=b*c;
            cout<<wynik<<endl;
            wynik=0;
        }if (a=='/')
        {
            wynik=b/c;
            cout<<wynik<<endl;
            wynik=0;
        }if (a=='%')
        {
            wynik=b%c;
            cout<<wynik<<endl;
            wynik=0;
        }
    }
    return 0;
}