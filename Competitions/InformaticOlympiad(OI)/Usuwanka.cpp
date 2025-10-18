//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    stack<int> pozycje,wyniki;
    int n,k;
    char a;
    cin>>n>>k;

    vector<int> sumpref(n+1);
    sumpref[0]=0;

    for(int i=1;i<=n;i++){
        cin>>a;
        if(a=='c'){
            pozycje.push(i);
            sumpref[pozycje.size()]=sumpref[pozycje.size()-1]-k;
        }else{
            pozycje.push(i);
            sumpref[pozycje.size()]=sumpref[pozycje.size()-1]+1;
        }
        if(pozycje.size()>=k+1 && sumpref[pozycje.size()]-sumpref[pozycje.size()-k-1]==0){
            for(int j=0;j<k+1;j++){
                wyniki.push(pozycje.top());
                pozycje.pop();
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<wyniki.top()<<" ";
        wyniki.pop();
        if(i%(k+1)==0){
            cout<<endl;
        }
    }
    return 0;
}