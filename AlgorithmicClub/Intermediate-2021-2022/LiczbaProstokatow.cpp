#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (int j=0;j<3;j++)
    {
    unsigned long long int n,wynik=0;
    cin >> n;
    for(int i=1; i<=sqrt(n); i++)
        {
        if(n % i == 0)
        {
           wynik++;
        }
        }
        cout<<wynik<<endl;
    }
    return 0;
}