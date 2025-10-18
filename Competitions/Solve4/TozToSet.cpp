#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>

using namespace __gnu_pbds;
using namespace std;
 
typedef tree<__int128_t, null_type, less<__int128_t>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

__int128_t modulo;
__int128_t potega(__int128_t a,__int128_t b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        __int128_t wynik=potega(a,b/2)%modulo;
        return (wynik*wynik)%modulo;
    }else{
        return (a*potega(a,b-1))%modulo;
    }

    return 0;
}

__int128_t read() {
    __int128_t x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128_t  x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main(){
    ordered_set tonieset;
    
    __int128_t t=1,q;
    modulo=read();
    q=read();

    while(q--){
        char znak;
        cin>>znak;
        if(znak=='+'){
            __int128_t a;
            a=read();
            tonieset.insert(potega(a,t));
        }
        if(znak=='-'){
            __int128_t b;
            b=read();
            tonieset.erase(potega(b,t));
        }
        if(znak=='?'){
            __int128_t c,d;
            c=read();
            d=read();
            t=tonieset.order_of_key(d+1)-tonieset.order_of_key(c);
            print(t);
            cout<<'\n';
        }
    }
 
    return 0;
}