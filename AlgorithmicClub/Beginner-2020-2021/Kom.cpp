#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    cout<<a[0];
    for(int i=1;i<a.size();i++)
    {

        if(a[i]==' ')
        {
            i++;
            if(a[i]<123&&a[i]>96)
            {
                char w=a[i];
                w-=32;
                cout<<w;
            }
            else cout<<a[i];
        }
        else cout<<a[i];
    }
    }