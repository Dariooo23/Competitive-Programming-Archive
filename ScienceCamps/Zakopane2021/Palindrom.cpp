#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int b;
        cin>>b;
        string slowo2,slowo1;
        cin>>slowo1;
        transform(slowo1.begin(),slowo1.end(),slowo1.begin(),::tolower);
        slowo2=slowo1;
        reverse(slowo2.begin(),slowo2.end());
        if(slowo2==slowo1)
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }

    }
    return 0;
}