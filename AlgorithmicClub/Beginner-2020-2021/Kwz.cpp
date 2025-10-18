#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    int n,w,a,r;
    cin>>n;
    a=pow(n,0.5);
    r=n-(a*a);
    w=(a*2+1)*a+a;
    if(r!=0)w+=r*2+1;
    if(r>=a+1)w++;
    cout<<w;
    return 0;
}