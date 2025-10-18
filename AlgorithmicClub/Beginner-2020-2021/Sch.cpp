#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int ILDW,LZS=0,COS=0;
    cin>>ILDW;
    int ZS[ILDW];
    for (int i=0;i<ILDW;i++)
    {
        cin>>ZS[i];
    }
    for (int i=0;i<ILDW;i++)
    {
        if (ZS[i]==1)
        {
          LZS=LZS+1;
        }

    }
    cout<<LZS<<endl;


for (int i=1;i<ILDW;i++)
{
    if (ZS[i]==1)
        cout<<ZS[i-1]<<" ";
}
cout<<ZS[ILDW-1];
    return 0;
}