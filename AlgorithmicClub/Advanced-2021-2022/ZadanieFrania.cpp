#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int przyjaciele,kolory,wynik=0;
    cin>>przyjaciele>>kolory;
    vector<int> dni;
    multiset<int> klamerki;
    for(int i=0;i<przyjaciele;i++)
    {
        int a;
        cin>>a;
        dni.push_back(a);
    }
    sort(dni.begin(),dni.end());
    reverse(dni.begin(),dni.end());
    for(int i=0;i<kolory;i++)
    {
        int b;
        cin>>b;
        klamerki.insert(b);
    }
    for(int i=0;i<przyjaciele;i++)
    {
        multiset<int>::iterator it=klamerki.lower_bound(5 * dni[i]);
        if(it!=klamerki.end())
        {
            wynik++;
            klamerki.erase(it);
        }
        else
        {
            wynik=wynik+2;
            it=klamerki.lower_bound(3*dni[i]);
            if(it!=klamerki.end())
            {
                klamerki.erase(it);
            }
            else
            {
                cout<<"NIE";
                exit(0);
            }
            it=klamerki.lower_bound(2*dni[i]);
            if(it!=klamerki.end())
            {
                klamerki.erase(it);
            }
            else
            {
                cout<<"NIE";
                exit(0);
            }
        }
    }
    cout<<wynik;
    return 0;
}