//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

struct naczynia{
    int a,b,c;
};

vector<vector<vector<int>>> dist;
vector<vector<vector<int>>> visited;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int A,B,C,D;
    cin>>A>>B>>C>>D;

    dist.resize(A+1,vector<vector<int>> (B+1, vector<int> (C+1,0)));
    visited.resize(A+1,vector<vector<int>> (B+1, vector<int> (C+1,0)));

    queue<naczynia> kolejka;
    kolejka.push({0,0,0});
    visited[0][0][0]=1;

    int wynik=0;
    while(!kolejka.empty()){
        naczynia punkt;
        naczynia kpunkt;
        //Operacja sprawdzenia czy osiagnieto D
        punkt=kolejka.front();
        if(punkt.a==D || punkt.b==D || punkt.c==D){
            cout<<dist[punkt.a][punkt.b][punkt.c];
            return 0;
        }
        //Operacje dolania wody
        if(!visited[A][punkt.b][punkt.c]){
            dist[A][punkt.b][punkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[A][punkt.b][punkt.c]=1;
            punkt.a=A;
            kolejka.push(punkt);
        }
        punkt=kolejka.front();
        if(!visited[punkt.a][B][punkt.c]){
            dist[punkt.a][B][punkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[punkt.a][B][punkt.c]=1;
            punkt.b=B;
            kolejka.push(punkt);
        }
        punkt=kolejka.front();
        if(!visited[punkt.a][punkt.b][C]){
            dist[punkt.a][punkt.b][C]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[punkt.a][punkt.b][C]=1;
            punkt.c=C;
            kolejka.push(punkt);
        }

        //Operacje oprozniania wody
        punkt=kolejka.front();
        if(!visited[0][punkt.b][punkt.c]){
            dist[0][punkt.b][punkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[0][punkt.b][punkt.c]=1;
            punkt.a=0;
            kolejka.push(punkt);
        }
        punkt=kolejka.front();
        if(!visited[punkt.a][0][punkt.c]){
            dist[punkt.a][0][punkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[punkt.a][0][punkt.c]=1;
            punkt.b=0;
            kolejka.push(punkt);
        }
        punkt=kolejka.front();
        if(!visited[punkt.a][punkt.b][0]){
            dist[punkt.a][punkt.b][0]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[punkt.a][punkt.b][0]=1;
            punkt.c=0;
            kolejka.push(punkt);
        }

        //Operacje przelewania wody;
        punkt=kolejka.front();
        //Z A do B
        kpunkt=kolejka.front();
        if(kpunkt.a+kpunkt.b<=B){
            kpunkt.b=kpunkt.b+kpunkt.a;
            kpunkt.a=0;
        }else{
            kpunkt.a=kpunkt.a+kpunkt.b-B;
            kpunkt.b=B;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }
        //Z A do C
        kpunkt=kolejka.front();
        if(kpunkt.a+kpunkt.c<=C){
            kpunkt.c=kpunkt.c+kpunkt.a;
            kpunkt.a=0;
        }else{
            kpunkt.a=kpunkt.a+kpunkt.c-C;
            kpunkt.c=C;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }

        //Z B do A
        kpunkt=kolejka.front();
        if(kpunkt.b+kpunkt.a<=A){
            kpunkt.a=kpunkt.a+kpunkt.b;
            kpunkt.b=0;
        }else{
            kpunkt.b=kpunkt.b+kpunkt.a-A;
            kpunkt.a=A;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }
        //Z B do C
        kpunkt=kolejka.front();
        if(kpunkt.b+kpunkt.c<=C){
            kpunkt.c=kpunkt.c+kpunkt.b;
            kpunkt.b=0;
        }else{
            kpunkt.b=kpunkt.b+kpunkt.c-C;
            kpunkt.c=C;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }

        //Z C do A
        kpunkt=kolejka.front();
        if(kpunkt.c+kpunkt.a<=A){
            kpunkt.a=kpunkt.a+kpunkt.c;
            kpunkt.c=0;
        }else{
            kpunkt.c=kpunkt.c+kpunkt.a-A;
            kpunkt.a=A;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }
        //Z C do B
        kpunkt=kolejka.front();
        if(kpunkt.c+kpunkt.b<=B){
            kpunkt.b=kpunkt.b+kpunkt.c;
            kpunkt.c=0;
        }else{
            kpunkt.c=kpunkt.c+kpunkt.b-B;
            kpunkt.b=B;
        }
        if(!visited[kpunkt.a][kpunkt.b][kpunkt.c]){
            dist[kpunkt.a][kpunkt.b][kpunkt.c]=dist[punkt.a][punkt.b][punkt.c]+1;
            visited[kpunkt.a][kpunkt.b][kpunkt.c]=1;
            kolejka.push(kpunkt);
        }
        kolejka.pop();
    }

    cout<<"NIE";
    return 0;
}