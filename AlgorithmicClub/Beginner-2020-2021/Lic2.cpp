#include <iostream>

using namespace std;

int main()
{
std::ios_base::sync_with_stdio(0);
    int k,lp=1,m=0,w=0;
    cin>>k;
    for (int i=0;i<k;i++)
    {

        if (k%lp!=0)
        {
            m=lp;
            break;
        }
        lp=lp+1;
    }
w=k-1;
    cout<<m<<" "<<w;
    return 0;
}