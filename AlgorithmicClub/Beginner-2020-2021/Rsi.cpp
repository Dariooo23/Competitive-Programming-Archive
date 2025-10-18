#include <cstdlib>
#include <iostream>
using namespace std;

long long silnia(int n)
{
 if(n<2)
        return 1;

return n*silnia(n-1);
}

int main()
{
 int n;


 cin>>n;
 cout<<silnia(n)<<endl;


 return 0;
}