//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int zdanek=0,zdanee=0,suma=0,zdanew=0;
    if(a>=40)zdanek++;
    if(b>=40)zdanek++;
    if(c>=40)zdanek++;
    if(d>=40)zdanee++;

    suma=a+b+c+d+d;
    if(suma>=250)zdanew=1;

    if(zdanek>=2 && zdanee>=1 && zdanew>=1){
        cout<<"ZDANY";
    }else{
        if(zdanek>=2 && zdanee>=1){
            cout<<"DOPYTKA";
        }else{
            cout<<"NIEZDANY";
        }
    }
    return 0;
}