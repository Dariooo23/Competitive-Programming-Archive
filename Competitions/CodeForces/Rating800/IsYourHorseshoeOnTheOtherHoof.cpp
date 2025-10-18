//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

map<int,int> podkowy;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a,b,c,d,wynik=0;
    cin>>a>>b>>c>>d;

    if(podkowy.find(a)==podkowy.end()){
        podkowy[a]=1;
    }else{
        podkowy[a]++;
        wynik++;
    }
    if(podkowy.find(b)==podkowy.end()){
        podkowy[b]=1;
    }else{
        podkowy[b]++;
        wynik++;
    }
    if(podkowy.find(c)==podkowy.end()){
        podkowy[c]=1;
    }else{
        podkowy[c]++;
        wynik++;
    }
    if(podkowy.find(d)==podkowy.end()){
        podkowy[d]=1;
    }else{
        podkowy[d]++;
        wynik++;
    }

    cout<<wynik;
    
    return 0;
}
 