#include <iostream>
#include <string>
using namespace std;
string a;
char b;
int c;
int main()
{
    cin>>a;

    for (int i=0;i<a.length();i++)
    {

        if (a[i]>=65 && a[i]<=90)
        {
            if(c==0)
            {
                cout<<a[i];
                c=1;
            }
            else
            {
                cout<<" ";
                b=a[i];
                a[i]=b+32;
                cout<<a[i];
            }
        }
        else
        {
            if (a[i]>=97 &&a[i]<=122)
            {
                cout<<a[i];
            }
            else
            {
                if (a[i]==46)
                {
                    cout<<". ";
                    c=0;
                }
                else
                    if(a[i]==59)
    {
        cout<<" ";
    }
    else
                {
                    cout<<a[i];
                }
            }
        }

    }
    return 0;
}