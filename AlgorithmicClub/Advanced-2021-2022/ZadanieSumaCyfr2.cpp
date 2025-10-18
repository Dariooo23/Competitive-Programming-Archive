#include <iostream>

using namespace std;
int tab[1000009],dynamik[2][1000009];
int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;

    for(int i=1;i<=a;i++)
    {
        cin>>tab[i];
    }
    for(int i=1;i<=a;i++)
    {
        dynamik[1][i]=tab[i]+(max(dynamik[1][i-1],dynamik[0][i-1]));
        dynamik[0][i]=dynamik[1][i-1]+9;
    }
    cout<<max(dynamik[0][a],dynamik[1][a]);
    return 0;
}