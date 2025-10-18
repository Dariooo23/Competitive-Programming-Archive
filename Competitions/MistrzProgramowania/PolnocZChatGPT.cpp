//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

struct struktura{
    int godzina,minuty,zmiana;
};

vector<struktura> daty;

bool cmp(const struktura &a, const struktura &b){
    if(a.godzina==b.godzina){
        return a.minuty<b.minuty;
    }else{
        return a.godzina<b.godzina;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    long long int n;

    cin>>n;

    daty.resize(n);

    for(int i=0;i<n;i++){
        int a,b,zmiana=0;
        cin>>a>>b;

        if(a>=12){
            zmiana=1;
            a-=12;
        }

        daty[i]={a,b,zmiana};
    }

    sort(daty.begin(),daty.end(),cmp);

    if(daty[0].zmiana==1){
        cout<<daty[0].godzina+12<<" ";
    }else{
        cout<<daty[0].godzina<<" ";
    }

    cout<<daty[0].minuty;
    return 0;
}