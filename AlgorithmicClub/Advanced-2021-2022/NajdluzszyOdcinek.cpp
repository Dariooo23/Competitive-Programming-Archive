// Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct punkt{
    long long int x, y;
};

vector<punkt> punkty;
vector<punkt> otoczka_g;
vector<punkt> otoczka_d;

bool cmp(const punkt &a, const punkt &b){
    if (a.x == b.x){
        return a.y < b.y;
    }
    else{
        return a.x < b.x;
    }
}

long long int odleglosc(const punkt &a, const punkt &b){
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

long long int iloczyn_wektorowy(const punkt &a, const punkt &b, const punkt &c){
    long long int x1 = c.x - a.x;
    long long int y1 = c.y - a.y;
    long long int x2 = c.x - b.x;
    long long int y2 = c.y - b.y;

    if (x1 * y2 - x2 * y1 > 0){
        return 1;
    }
    if (x1 * y2 - x2 * y1 < 0){
        return -1;
    }
    return 0;
}

void stworz_otoczka(){
    for (int i = 0; i < punkty.size(); i++){
        while (otoczka_g.size() > 1 && iloczyn_wektorowy(otoczka_g[otoczka_g.size() - 2], otoczka_g[otoczka_g.size() - 1], punkty[i]) >= 0){
            otoczka_g.pop_back();
        }
        otoczka_g.push_back(punkty[i]);
    }
    otoczka_g.pop_back();

    for (int i = punkty.size() - 1; i >= 0; i--){
        while (otoczka_d.size() > 1 && iloczyn_wektorowy(otoczka_d[otoczka_d.size() - 2], otoczka_d[otoczka_d.size() - 1], punkty[i]) >= 0){
            otoczka_d.pop_back();
        }
        otoczka_d.push_back(punkty[i]);
    }
    otoczka_d.pop_back();
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n, wynik = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        long long int x, y;
        cin >> x >> y;
        punkty.push_back({x, y});
    }

    sort(punkty.begin(), punkty.end(), cmp);

    stworz_otoczka();

    for (int i = 0; i < otoczka_g.size(); i++){
        for (int j = 0; j < otoczka_d.size(); j++){
            wynik = max(wynik, odleglosc(otoczka_g[i], otoczka_d[j]));
        }
    }

    cout << fixed << setprecision(7) << (long double)(sqrtl(wynik));
    return 0;
}
