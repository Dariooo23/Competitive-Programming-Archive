#include <iostream>

using namespace std;

int main()
{
    int We,wynik;
    cin>>We;
if (We==0)
{
    cout<<1;
}
if (We>1 && We<12)
{
    cout<<12;
}if (We>12 && We<23)
{
    cout<<23;
}if (We>23 && We<34)
{
    cout<<34;
}if (We>34 && We<45)
{
    cout<<45;
}if (We>45 && We<56)
{
    cout<<56;
}if (We>56 && We<67)
{
    cout<<67;
}if (We>67 && We<78)
{
    cout<<78;
}if (We>78 && We<89)
{
    cout<<89;
}if (We>89 && We<100)
{
    cout<<100;
}
if (We==12||We==23||We==34||We==45||We==56||We==67||We==78||We==89||We==1)
{
    cout<<"NIE";
}






    return 0;
}