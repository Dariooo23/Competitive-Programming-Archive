//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct struktura{
    long long int typ,x,y1,y2,nr;
};

vector<struktura> zamiatanie;
vector<pair<long long int,long long int>> punkty;
vector<pair<pair<long long int,long long int>,pair<long long int,long long int>>> przedzialy;
vector<pair<pair<long long int,long long int>,pair<long long int,long long int>>> wyniki;

const long long int M=1<<20;
vector<long long int> tree(M*2);
long long int query(long long int pocz,long long int kon)
{
    pocz=pocz+M;
    kon=kon+M;
    long long int wynik=tree[pocz];
    if(pocz!=kon)
    {
        wynik=wynik+tree[kon];
    }

    while(pocz/2!=kon/2)
    {
        if(pocz%2==0)
        {
            wynik=wynik+tree[pocz+1];
        }
        if(kon%2==1)
        {
            wynik=wynik+tree[kon-1];
        }
        pocz=pocz/2;
        kon=kon/2;
    }
    return wynik;
}

void update(long long int x,long long int y){
    x=x+M;
    tree[x]=tree[x]+y;
    while(x!=1)
    {
        x=x/2;
        tree[x]=tree[2*x]+tree[2*x+1];
    }

}

bool cmp1(const struktura &a,const struktura &b){
    if(a.x==b.x){
        return a.typ<b.typ;
    }else{
        return a.x<b.x;
    }
}
bool cmp2(const struktura &a,const struktura &b){
    if(a.x==b.x){
        return a.typ>b.typ;
    }else{
        return a.x<b.x;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n,m;
    cin>>n>>m;
    wyniki.resize(m+1);

    for(int i=1;i<=n;i++){
        long long int y;
        cin>>y;
        punkty.push_back({i,y});
    }
    for(int i=0;i<m;i++){
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        przedzialy.push_back({{a,b},{c,d}});
    }

    //Zamiatanie od lewej
    for(int i=0;i<n;i++){
        zamiatanie.push_back({1,punkty[i].first,punkty[i].second,-1,-1});
    }
    for(int i=0;i<m;i++){
        zamiatanie.push_back({0,przedzialy[i].first.first,przedzialy[i].first.second,przedzialy[i].second.second,i});
    }
    sort(zamiatanie.begin(),zamiatanie.end(),cmp1);
    for(int i=0;i<zamiatanie.size();i++){
        if(zamiatanie[i].typ==1){
            update(zamiatanie[i].y1,1);
        }else{
            if(zamiatanie[i].y1-1>=1){
                wyniki[zamiatanie[i].nr].first.first=query(1,zamiatanie[i].y1-1);
            }else{
                wyniki[zamiatanie[i].nr].first.first=0;
            }
            if(zamiatanie[i].y2+1<=n){
                wyniki[zamiatanie[i].nr].first.second=query(zamiatanie[i].y2+1,n);
            }else{
                wyniki[zamiatanie[i].nr].first.second=0;
            }
        }
    }


    //Zamiatanie od prawej
    zamiatanie.clear();
    for(int i=0;i<n;i++){
        zamiatanie.push_back({1,punkty[i].first,punkty[i].second,-1,-1});
    }
    for(int i=0;i<m;i++){
        zamiatanie.push_back({0,przedzialy[i].second.first,przedzialy[i].first.second,przedzialy[i].second.second,i});
    }
    sort(zamiatanie.begin(),zamiatanie.end(),cmp2);
    tree.clear();
    tree.resize(M*2);
    for(int i=zamiatanie.size()-1;i>=0;i--){
        if(zamiatanie[i].typ==1){
            update(zamiatanie[i].y1,1);
        }else{
            if(zamiatanie[i].y1-1>=1){
                wyniki[zamiatanie[i].nr].second.first=query(1,zamiatanie[i].y1-1);
            }else{
                wyniki[zamiatanie[i].nr].second.first=0;
            }
            if(zamiatanie[i].y2+1<=n){
                wyniki[zamiatanie[i].nr].second.second=query(zamiatanie[i].y2+1,n);
            }else{
                wyniki[zamiatanie[i].nr].second.second=0;
            }
        }
    }

    for(int i=0;i<m;i++){
        long long int wynik=0,dlugosc=0;
        //Lewo
        dlugosc=przedzialy[i].first.first-1;
        wynik=wynik+(dlugosc*(dlugosc-1))/2;
        //Prawo
        dlugosc=n-przedzialy[i].second.first;
        wynik=wynik+(dlugosc*(dlugosc-1))/2;
        //Dol
        dlugosc=przedzialy[i].first.second-1;
        wynik=wynik+(dlugosc*(dlugosc-1))/2;
        //Gora
        dlugosc=n-przedzialy[i].second.second;
        wynik=wynik+(dlugosc*(dlugosc-1))/2;

        //Lewy Dolny
        dlugosc=wyniki[i].first.first;
        wynik=wynik-(dlugosc*(dlugosc-1))/2;
        //Lewy Gorny
        dlugosc=wyniki[i].first.second; 
        wynik=wynik-(dlugosc*(dlugosc-1))/2;
        //Prawy Dolny
        dlugosc=wyniki[i].second.first;
        wynik=wynik-(dlugosc*(dlugosc-1))/2;
        //Prawy Gorny
        dlugosc=wyniki[i].second.second;
        wynik=wynik-(dlugosc*(dlugosc-1))/2;

        cout<<(n*(n-1))/2-wynik<<endl;
    }

    return 0;
}