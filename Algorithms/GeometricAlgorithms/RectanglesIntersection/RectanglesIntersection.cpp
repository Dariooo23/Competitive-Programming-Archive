//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

struct prostokat{
    int x1,y1,x2,y2;
};

pair<long long int,prostokat> wspolne_pole_prostokatow(const prostokat &prostokat1, const prostokat &prostokat2)
{
    int x1=max(prostokat1.x1,prostokat2.x1),y1=max(prostokat1.y1,prostokat2.y1);
    int x2=min(prostokat1.x2,prostokat2.x2),y2=min(prostokat1.y2,prostokat2.y2);

    int bok1=x2-x1;
    int bok2=y2-y1;

    pair<long long int,prostokat> wyjscie;
    wyjscie.first=(long long int)bok1*bok2;
    wyjscie.second.x1=x1;
    wyjscie.second.y1=y1;
    wyjscie.second.x2=x2;
    wyjscie.second.y2=y2;

    if(bok1<0)
    {
        wyjscie.first=0;
    }
    if(bok2<0)
    {
        wyjscie.first=0;
    }

    return wyjscie;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    prostokat prostokat1,prostokat2;

    //Wczytaj dwa prostokąty podając lewy dolny i prawy dolny róg tych prostokątów
    cin>>prostokat1.x1>>prostokat1.y1>>prostokat1.x2>>prostokat1.y2;
    cin>>prostokat2.x1>>prostokat2.y1>>prostokat2.x2>>prostokat2.y2;

    //Funkcja zwraca wspólne pole prostokątów (Lub zero jeżeli takie nie istnieje) w zmiennej .first, natomiast w .second znajduja się lewy dolny oraz prawy górny wierzchołek powstałego prostokąta
    cout<<wspolne_pole_prostokatow(prostokat1,prostokat2).first<<endl;
    
    return 0;
}
 