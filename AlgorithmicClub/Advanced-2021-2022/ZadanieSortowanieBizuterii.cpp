#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int comparator(string slowo,string slowo1)
{
    if(slowo.size()==slowo1.size())
    {
        return slowo<slowo1;
    }
    else
    {
        return slowo.size()<slowo1.size();
    }
}



int main()
{
    int a;
    cin>>a;
    string slowa[a];
    for(int i=0;i<a;i++)
    {
        cin>>slowa[i];
    }
    sort(slowa,slowa+a,comparator);
    for(int i=0;i<a;i++)
    {
        cout<<slowa[i]<<endl;
    }
    return 0;
}