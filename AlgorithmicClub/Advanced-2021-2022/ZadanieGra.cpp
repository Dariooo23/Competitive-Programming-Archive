#include <iostream>

using namespace std;
int tab[1000009],tab2[1000009];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=max(1,i-6);j<i;j++)
        {
            if(j==max(1,i-6))
            {
                tab2[i]=tab2[j];
            }
            else
            {
                tab2[i]=max(tab2[j],tab2[i]);
            }
        }
        tab2[i]=tab2[i]+tab[i];

    }
    cout<<tab2[n];
    return 0;
}