//Karol Dziekan 
#include <bits/stdc++.h>

using namespace std;
  
struct punkt{
    int x;
    int y;
};
  
bool przeciecie(punkt p, punkt q, punkt r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}

int kierunek(punkt p, punkt q, punkt r){
    int val =(q.y - p.y)*(r.x - q.x)-(q.x - p.x)*(r.y - q.y);
    if(val == 0)return 0; 
    return (val > 0)? 1: 2; 
}
  

bool czyprzeciecie(punkt p1, punkt q1, punkt p2, punkt q2){

    int o1 = kierunek(p1, q1, p2);
    int o2 = kierunek(p1, q1, q2);
    int o3 = kierunek(p2, q2, p1);
    int o4 = kierunek(p2, q2, q1);
    if (o1 != o2 && o3 != o4)return true;
    if (o1 == 0 && przeciecie(p1, p2, q1)) return true;
    if (o2 == 0 && przeciecie(p1, q2, q1)) return true;
    if (o3 == 0 && przeciecie(p2, p1, q2)) return true;
    if (o4 == 0 && przeciecie(p2, q1, q2)) return true;
  
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    struct punkt p1,q1;
    struct punkt p2,q2;
    cin>>p1.x>>p1.y>>q1.x>>q1.y;
    cin>>p2.x>>p2.y>>q2.x>>q2.y;
  
    czyprzeciecie(p1, q1, p2, q2)? cout << "TAK\n": cout << "NIE\n";
    return 0;
}