#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n,k,a,i=0;
    cin>>n>>k>>a;
   n=n%(k+a);
while(n>=0)
{
    if(i%2==0)
    {
        n-=k;
        if(n<0)
        {
            cout<<1;
        }
    }
    else
    {
        if(i%2==1)
        {
            n-=a;
            if(n<0)
            {
                cout<<0;
            }
        }
    }
    i++;
}


    return 0;
}