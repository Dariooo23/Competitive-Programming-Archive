#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
struct punkt
{
    int x,y,z;
};
bool operator<(punkt const& a,punkt const& b)
{
    int w1=0,w2=0;
    if(a.x>0) w1+=a.x;
    else w1-=a.x;
    if(a.y>0) w1+=a.y;
    else w1-=a.y;
    if(a.z>0) w1+=a.z;
    else w1-=a.z;
    if(b.x>0) w2+=b.x;
    else w2-=b.x;
    if(b.y>0) w2+=b.y;
    else w2-=b.y;
    if(b.z>0) w2+=b.z;
    else w2-=b.z;

    if(w1<w2) return true;
    else return false;
}
punkt tab[1000000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i].x>>tab[i].y>>tab[i].z;
    }
    sort(tab,tab+n);
    for(int i=0;i<n;i++)
    {
    cout<<tab[i].x<<" "<<tab[i].y<<" "<<tab[i].z<<endl;
    }

}