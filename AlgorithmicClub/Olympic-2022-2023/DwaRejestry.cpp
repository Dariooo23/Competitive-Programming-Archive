//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<bool> odpowiedz;
void solve(int n){
    int x,y,wynik=1e9;
    odpowiedz.clear();
    for(int i=1;i<n/2+1;i++){
        x=n;
        y=i;

        int licznik=0;
        vector<bool> odpowiedz2;
        if(gcd(x,y)>1)continue;
        while((x!=1 || y!=1) && licznik<38){
            if(x>y){
                x=x-y;
                odpowiedz2.push_back(0);
            }else{
                y=y-x;
                odpowiedz2.push_back(1);
            }
            licznik++;
        }

        if(x!=1 || y!=1)continue;

        if(licznik<wynik){
            wynik=licznik;
            odpowiedz=odpowiedz2;
        }else{
            if(licznik==wynik){
                int flaga=0;
                for(int k=licznik-1;k>=0;k--){
                    if(odpowiedz[k]!=odpowiedz2[k]){
                        if(odpowiedz2[k]==0){
                            flaga=1;
                            break;
                        }else{
                            break;
                        }
                    }
                }
                if(flaga==1){
                    odpowiedz=odpowiedz2;
                }
            }
        }


        x=n;
        y=n-i;

        licznik=0;
        odpowiedz2.clear();
        if(gcd(x,y)>1)continue;
        while((x!=1 || y!=1) && licznik<38){
            if(x>y){
                x=x-y;
                odpowiedz2.push_back(0);
            }else{
                y=y-x;
                odpowiedz2.push_back(1);
            }
            licznik++;
        }

        if(licznik<wynik){
            wynik=licznik;
            odpowiedz=odpowiedz2;
        }else{
            if(licznik==wynik){
                int flaga=0;
                for(int k=licznik-1;k>=0;k--){
                    if(odpowiedz[k]!=odpowiedz2[k]){
                        if(odpowiedz2[k]==0){
                            flaga=1;
                            break;
                        }else{
                            break;
                        }
                    }
                }
                if(flaga==1){
                    odpowiedz=odpowiedz2;
                }
            }
        }
    }

    if(wynik==1e9)return;
    for(int i=wynik-1;i>=0;i--){
        if(odpowiedz[i]==0){
            cout<<"X";
        }else{
            cout<<"Y";
        }
    }

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n,wynik=1e9;
    cin>>n;
    solve(n);

    return 0;
}
 