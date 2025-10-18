#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    string zdanie,zdanie1;
    cin>>zdanie1;
    zdanie=zdanie1+' ';
    while(cin>>zdanie1)
    {
        zdanie=zdanie+zdanie1+' ';
    }
    zdanie.erase(zdanie.size()-1);
    //cout<<zdanie;
    int x=zdanie.size();

    char tab[x];
    for (int i=0;i<zdanie.size();i++)
    {

        tab[i]=zdanie[i];

    }

    for (int i=0;i<zdanie.size();i++)
    {
        if (tab[i]==' ')
        {
            swap (tab[i-1],tab[i+1]);
        }
    }
    swap(tab[0],tab[x-1]);
    for (int i=0;i<zdanie.size();i++)
    {
        cout<<tab[i];
    }
    return 0;
}