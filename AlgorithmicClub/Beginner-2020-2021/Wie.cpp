#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    int a;
    cin>>a;
    for (int i=0;i<a;i++)
    {
        int b,c,d,wynik=0;
        cin>>b>>c;
        for (int j=0;j<c;j++)
        {
            cin>>d;
            if (d==b)
            {
                wynik++;
            }
        }
        cout<<wynik<<endl;
    }
    return 0;
}