//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

int n,k;
struct punkt{
    long long int x,y;
};
struct wynik{
    punkt punkt1,punkt2;
};
vector<punkt> punktyg;

long long int iloczyn_wektorowy(const punkt &a, const punkt &b, const punkt &c){
    long long int x1=c.x-a.x;
    long long int y1=c.y-a.y;
    long long int x2=c.x-b.x;
    long long int y2=c.y-b.y;

    if (x1*y2-x2*y1>0){
        return 1;
    }
    if (x1*y2-x2*y1<0){
        return -1;
    }
    return 0;
}

void wypisz(vector<wynik> wyniki){
    cout<<"TAK"<<endl;
    for(int i=0;i<wyniki.size();++i){
        cout<<wyniki[i].punkt1.x<<" "<<wyniki[i].punkt1.y<<" "<<
              wyniki[i].punkt2.x<<" "<<wyniki[i].punkt2.y<<endl;
    }

    return;
}
bool strzelaj(){
    vector<punkt> punkty=punktyg;
    vector<punkt> punkty2;
    vector<wynik> wyniki;

    punkt punkt1,punkt2;
    for(int i=1;i<=k;++i){
        int indeks1,indeks2;

        if(punkty.size()==0){
            wyniki.push_back({punkt1,punkt2});
            continue;
        }
        if(punkty.size()==1){
            punkt1=punkty[0];
            punkt2=punkt1;

            if(punkt2.x==-1e9){
                punkt2.x++;
            }else{
                punkt2.x--;
            }
            if(punkt2.y==-1e9){
                punkt2.y++;
            }else{
                punkt2.y--;
            }

            wyniki.push_back({punkt1,punkt2});
            punkty.clear();
            continue;
        }

        while(true){
            indeks1=rand()%punkty.size();
            indeks2=rand()%punkty.size();
            if(indeks1!=indeks2){
                break;
            }
        }

        punkt1=punkty[indeks1];
        punkt2=punkty[indeks2];
        wyniki.push_back({punkt1,punkt2});

        for(int j=0;j<punkty.size();++j){
            if(j==indeks1 || j==indeks2)continue;
            if(iloczyn_wektorowy(punkt1,punkt2,punkty[j])!=0){
                punkty2.push_back(punkty[j]);
            }
        }

        punkty.clear();
        punkty=punkty2;
        punkty2.clear();
    }

    if(punkty.size()!=0){
        return 0;
    }else{
        wypisz(wyniki);
        return 1;
    }
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    srand(2137);
    cin>>n>>k;

    for(int i=0;i<n;++i){
        punkt punkt1;
        cin>>punkt1.x>>punkt1.y;
        punktyg.push_back(punkt1);
    }

    int licznik=160;
    while(licznik){
        if(strzelaj()){
            exit(0);
        }
        licznik--;
    }

    cout<<"NIE";
    return 0;
}