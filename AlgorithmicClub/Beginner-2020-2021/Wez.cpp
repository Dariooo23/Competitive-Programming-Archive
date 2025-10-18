#include <iostream>

using namespace std;

int main()
{
    int a,zmiana=0,l1=1;
    cin>>a;

    for (int i=0;i<a;i++)
    {
if (zmiana==0)
{
     for (int j=1;j<a+1;j++)
        {
            cout<<l1<<" ";

            l1=l1+1;
        }
        l1=l1+a-1;
        zmiana=1;
}
else
{
    for (int k=1;k<a+1;k++)
    {
        cout<<l1<<" ";
        l1=l1-1;
    }
    l1=l1+1+a;
    zmiana=0;
}

        cout<<endl;
    }




    return 0;
}