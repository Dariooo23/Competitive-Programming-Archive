//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<long long int> pi;
long long int pierwiastek;

void kmp(string slowo){
    pi.resize(slowo.size());
    pi[0]=0;

    for(int i=1;i<slowo.size();i++){
        int prefiks=pi[i-1];
        while(prefiks>0 && slowo[prefiks]!=slowo[i]){
            prefiks=pi[prefiks-1];
        }
        if(slowo[prefiks]==slowo[i])prefiks++;
        pi[i]=prefiks;
    }

    if(slowo.size()%(slowo.size()-pi[slowo.size()-1])==0){
        pierwiastek=slowo.size()-pi[slowo.size()-1];
    }else{
        pierwiastek=slowo.size();
    }

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string slowo;
    cin>>slowo;
    kmp(slowo);

    cout<<pierwiastek;

    return 0;
}
 