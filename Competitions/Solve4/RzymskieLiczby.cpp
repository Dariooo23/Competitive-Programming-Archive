//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<char> t1={'M','D','C','L','X','V','I'};
vector<string> t2={"CM","CD","XC","XL","IX","IV","I"};
vector<int> t3={1000,500,100,50,10,5,1};
vector<int> t4={900,400,90,40,9,4,1};

string zamiana(int n)
{
    string wynik="";
    int j=0;
    while(n>0){
        if(n>=t3[j]){
            n=n-t3[j];
            wynik=wynik+t1[j];
        }else{
            if(n>=t4[j]){
                n=n-t4[j];
                wynik=wynik+t2[j];
            }else{
                j++;
            }
        }
    }

    return wynik;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;
    cout<<zamiana(n);
    return 0;
}