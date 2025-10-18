//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

long long int modulog=1019043214942321;
vector<__int128_t> rozklad={100043,100853,100999};
vector<pair<__int128_t,__int128_t>> cykle={{250,183470},{16037,153792},{55162,86792}};

vector<__int128_t> dp;
vector<__int128_t> odpowiedzi;

__int128_t oblicz_dp(__int128_t n,__int128_t modulo){
    dp.resize(n+1,0);
    odpowiedzi.resize(n+1,0);

    dp[0]=((__int128_t)1)%modulo;
    dp[1]=((__int128_t)2)%modulo;
    odpowiedzi[0]=((__int128_t)1)%modulo;
    odpowiedzi[1]=((__int128_t)1)%modulo;

    for(int i=2;i<=n;i++){
        if(i-1>=0)odpowiedzi[i]=(__int128_t)(odpowiedzi[i]+dp[i-1])%modulo;
        if(i-2>=0)odpowiedzi[i]=(__int128_t)(odpowiedzi[i]+dp[i-2])%modulo;

        __int128_t liczba;
        liczba=((__int128_t)(dp[i-1]+dp[i-2]))%modulo;
        liczba=((__int128_t)(((__int128_t)(liczba*liczba))%modulo)*liczba)%modulo;
        dp[i]=((__int128_t)(((__int128_t)(liczba+dp[i-1])%modulo)+dp[i-2]))%modulo;

    }

    dp.clear();
    odpowiedzi.clear();
    return odpowiedzi[n];
}

__int128_t modulo_pot;
__int128_t potega(__int128_t a,__int128_t b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        __int128_t wynik=potega(a,b/2);
        return (wynik*wynik)%modulo_pot;
    }else{
        return (a*potega(a,b-1))%modulo_pot;
    }
}
long long int chinskie_reszty(vector<pair<__int128_t,__int128_t>> const &rownania){
    __int128_t modulo=1;
    for(auto const &rownanie:rownania){
        modulo*=rownanie.second;
    }

    __int128_t wynik=0;
    for(auto const &rownanie:rownania){
        __int128_t a=rownanie.first;
        __int128_t b=modulo/rownanie.second;

        modulo_pot=rownanie.second;
        __int128_t c=potega(b,rownanie.second-2);

        wynik=(wynik+a*b%modulo*c)%modulo;
    }
    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    __int128_t kopia_n1=n,kopia_n2=n,kopia_n3=n;

    kopia_n1-=cykle[0].first;
    kopia_n1%=cykle[0].second;
    kopia_n1+=cykle[0].first;

    kopia_n2-=cykle[1].first;
    kopia_n2%=cykle[1].second;
    kopia_n2+=cykle[1].first;

    kopia_n3-=cykle[2].first;
    kopia_n3%=cykle[2].second;
    kopia_n3+=cykle[2].first;

    pair<__int128_t,__int128_t> wynik1,wynik2,wynik3;
    wynik1={oblicz_dp(kopia_n1,rozklad[0]),rozklad[0]};
    wynik2={oblicz_dp(kopia_n2,rozklad[1]),rozklad[1]};
    wynik3={oblicz_dp(kopia_n3,rozklad[2]),rozklad[2]};

    cout<<(chinskie_reszty({wynik1,wynik2,wynik3})%modulog);
    return 0;
}