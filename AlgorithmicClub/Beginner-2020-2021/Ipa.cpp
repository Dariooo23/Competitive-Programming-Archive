#include <iostream>

using namespace std;

int odw(int a)
{
    int tmp=0;
    while(a>0)
    {

        tmp*=10;
        tmp=tmp+a%10;
        a/=10;
    }
    return tmp;
}

int main()
{
    int n,a;
    int flaga;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a;
        flaga=0;
        for(int j=11; j*j<=a; j++)
        {
            if(a%j==0 && j==odw(j) && (a/j==odw(a/j)))flaga=1;
           // cout << "XD" << a%j << " " << odw(j) << " "<< odw(a/j) << " " << flaga <<  endl;
        }
        if(flaga==1)
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }






}