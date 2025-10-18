#include <iostream>


using namespace std;

int power_modulo_fast(int a, int b, int m)
{
long long int i;
long long int result = 1;
long long int x = a%m;

for (i=1; i<=b; i<<=1)
{
x %= m;
if ((b&i) != 0)
{
result *= x;
result %= m;
}
x *= x;
}

return result;
}



int main()
{
long long int x,y;
int m=1000000007,a;
cin>>a;
for (int i=0;i<a;i++)
{
    cin>>x;
    y=1000000005;
    cout<<power_modulo_fast(x,y,m)<<endl;
}

return 0;
}