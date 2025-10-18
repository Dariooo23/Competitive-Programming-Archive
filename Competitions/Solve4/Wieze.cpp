//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n,m,sum1=0,sum2=0;
    cin>>n>>m;

    vector<int> wieze1(n);
    vector<int> wieze2(m);

    for(int i=0;i<n;i++){
        cin>>wieze1[i];
        sum1=sum1+wieze1[i];
    }
    for(int i=0;i<m;i++){
        cin>>wieze2[i];
        sum2=sum2+wieze2[i];
    }

    int indeks1=n-1,indeks2=m-1,wynik=0;
    while(sum1!=sum2){
        if(sum1>sum2){
            sum1=sum1-wieze1[indeks1];
            indeks1--;
            wynik++;
        }else{
            sum2=sum2-wieze2[indeks2];
            indeks2--;
            wynik++;
        }
    }

    cout<<wynik;
    return 0;
}