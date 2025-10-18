//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

vector<int> pewne;

void koniec(){
    cout<<"NIE";
    exit(0);
}
void policz_wynik1(string kameleony, int n){
    if(kameleony[0]=='Z'){
        pewne[0]=1;
        pewne[1]=1;
    }else{
        pewne[0]=1;
        pewne[1]=-1;
    }
    for(int i=3;i<n;i++){
        if(pewne[i]==0){
            int jedynki=0;
            if(pewne[i-1]==1)jedynki++;
            if(pewne[i-2]==1)jedynki++;
            if(kameleony[i-1]=='Z'){
                if(jedynki%2==0){
                    pewne[i]=-1;
                }else{
                    pewne[i]=1;
                }
            }else{
                if(jedynki%2==0){
                    pewne[i]=1;
                }else{
                    pewne[i]=-1;
                }
            }
        }
    }

    cout<<"TAK"<<endl;
    for(int i=0;i<n;i++){
        if(pewne[i]==1){
            cout<<i+1<<" ";
        }
    }
}
void policz_wynik2(string kameleony, int n){
    for(int i=0;i<n;i++){
        if(pewne[i]==0){
            int jedynki=0;
            if(pewne[i-1]==1)jedynki++;
            if(pewne[i+1]==1)jedynki++;
            if(kameleony[i]=='Z'){
                if(jedynki%2==0){
                    pewne[i]=-1;
                }else{
                    pewne[i]=1;
                }
            }else{
                if(jedynki%2==0){
                    pewne[i]=1;
                }else{
                    pewne[i]=-1;
                }
            }
        }
    }

    cout<<"TAK"<<endl;
    for(int i=0;i<n;i++){
        if(pewne[i]==1){
            cout<<i+1<<" ";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;

    string kameleony;
    cin>>kameleony;

    pewne.resize(n,0);
    int poprzednie=0,flaga=0;

    for(int i=0;i<n;i++){
        if(kameleony[i]=='C'){
            flaga=1;
        }
    }

    if(kameleony.size()==2 && kameleony[0]!=kameleony[1])koniec();
    if(flaga==0){
        cout<<"TAK"<<endl;
        return 0;
    }

    for(int i=0;i<n;i=i+3){
        if(i+2>=n)break;
        if(kameleony[i]==kameleony[i+1]){
            if(poprzednie){
                pewne[i+2]=1;
                poprzednie=1;
            }else{
                pewne[i+2]=-1;
                poprzednie=0;
            }
        }else{
            if(poprzednie){
                pewne[i+2]=-1;
                poprzednie=0;
            }else{
                pewne[i+2]=1;
                poprzednie=1;
            }
        }
    }

    poprzednie=0;
    for(int i=n-1;i>=0;i=i-3){
        if(i-2<0)break;
        if(kameleony[i]==kameleony[i-1]){
            if(poprzednie){
                if(pewne[i-2]==-1)koniec();
                pewne[i-2]=1;
                poprzednie=1;
                
            }else{
                if(pewne[i-2]==1)koniec();
                pewne[i-2]=-1;
                poprzednie=0;
            }
        }else{
            if(poprzednie){
                if(pewne[i-2]==1)koniec();
                pewne[i-2]=-1;
                poprzednie=0;
            }else{
                if(pewne[i-2]==-1)koniec();
                pewne[i-2]=1;
                poprzednie=1;
            }
        }
    }

    if(kameleony.size()%3==2)policz_wynik1(kameleony,n);
    else policz_wynik2(kameleony,n);
    return 0;
}