#include <iostream>

using namespace std;

int main()
{
    int x1,y1,x2,y2;
     int gx=0,gy=0;
   while (cin>>x1)
   {

       cin>>y1>>x2>>y2;
       gx=x2-x1;
       gy=y2-y1;
       cout<<gx<<" "<<gy<<endl;
   }
    return 0;
}