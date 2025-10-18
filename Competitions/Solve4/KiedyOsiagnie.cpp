//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

void print(__int128_t  x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
__int128_t read() {
    __int128_t x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

bool sprawdz(__int128_t mid,__int128_t n){
    __int128_t liczba=mid*2-1;
    if((((liczba)*(liczba+1))/2)-(((mid-1)*(mid))/2)>=n){
        return 0;
    }else{
        return 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    __int128_t n;
    n=read();

    __int128_t l=1,r=1e18,mid;
    while(l<r){
        mid=(l+r)/2;
        if(sprawdz(mid,n)){
            l=mid+1;
        }else{
            r=mid;
        }
    }

    print(l);
    return 0;
}