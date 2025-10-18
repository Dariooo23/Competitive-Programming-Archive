//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    string liczba;
    cin>>liczba;

    for(int i=0;i<liczba.size();i++){
        if(liczba[i]=='1'){
            cout<<"pa";
        }
        if(liczba[i]=='2'){
            cout<<"re";
        }
        if(liczba[i]=='3'){
            cout<<"ci";
        }
        if(liczba[i]=='4'){
            cout<<"vo";
        }
        if(liczba[i]=='5'){
            cout<<"mu";
        }
        if(liczba[i]=='6'){
            cout<<"xa";
        }
        if(liczba[i]=='7'){
            cout<<"ze";
        }
        if(liczba[i]=='8'){
            cout<<"bi";
        }
        if(liczba[i]=='9'){
            cout<<"so";
        }
        if(liczba[i]=='0'){
            cout<<"no";
        }
    }
    return 0;
}