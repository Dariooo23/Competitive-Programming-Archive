#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int rek(int n,int g){
   if(n==g) return n;
   else if(n>g) return rek(n-g,g);
   else return rek(n,g-n);
}
int main () {
   int x,y;

   cin >> x;
   cin >>y;
   cout<< rek(x,y);


return 0;

}