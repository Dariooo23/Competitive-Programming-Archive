#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,b,wynik=0,c=0;
    cin>>a>>b;
    for (int i=0;i<b;i++)
    {
        cin>>c;
        wynik=wynik+c;
    }
    if (wynik>=a)
    {
        cout<<"0";
    }
    else
    {
        cout<<a-wynik;
    }
    return 0;
}