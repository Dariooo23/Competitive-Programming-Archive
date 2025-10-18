#include <iostream>

using namespace std;

struct punkt
{
    int x;
    int y;
};
struct wekt
{
    int x,y;
};

wekt wektor(punkt A,punkt B)
{
    wekt C={B.x-A.x, B.y-A.y};
    return C;
}
float il_wek(punkt A,punkt B,punkt C)
{
    wekt a=wektor(B,A);
    wekt b=wektor(B,C);
    return a.x*b.y-a.y*b.x;


}
int main()
{
   int N;
   cin>>N;
   punkt a,b,c;
   cin>>b.x>>b.y>>c.x>>c.y;
   for(int i=2;i<N;i++)
   {
       a=b;
       b=c;
       cin>>c.x>>c.y;
       if(il_wek(a,b,c)>0)
       {
           cout<<"P\n";
       }
       else
       {
           cout<<"L\n";
       }

   }





}