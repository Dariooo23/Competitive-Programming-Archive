//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

const int maks=1e9,mini=-1e9;
struct punkt{
    int x,y;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    punkt lewyg={maks,mini},lewyd={maks,maks},prawyg={mini,mini},prawyd={mini,maks};
    for(int i=0;i<n;i++){
        int x,y,h;
        cin>>x>>y>>h;

        punkt punkt1;
        lewyd.x=min(lewyd.x,x-h);
        lewyd.y=min(lewyd.y,y-h);
        lewyg.x=min(lewyg.x,x-h);
        lewyg.y=max(lewyg.y,y+h);
        prawyg.x=max(prawyg.x,x+h);
        prawyg.y=max(prawyg.y,y+h);
        prawyd.x=max(prawyd.x,x+h);
        prawyd.y=min(prawyd.y,y-h);
    }

    int min_x=min(lewyd.x,lewyg.x),maks_x=max(prawyd.x,prawyg.x),min_y=min(lewyd.y,prawyd.y),maks_y=max(lewyg.y,prawyg.y);

    int bok_x=maks_x-min_x,bok_y=maks_y-min_y;
    if(bok_x>bok_y){
        min_y=min_y-(bok_x-bok_y);
        bok_y=bok_x;

        cout<<min_x+(bok_x/2)<<" "<<min_y+(bok_y/2)<<" "<<((bok_x-1)/2+1);
        return 0;
    }
    if(bok_x<bok_y){
        min_x=min_x-(bok_y-bok_x);
                bok_x=bok_y;

        cout<<min_x+(bok_x/2)<<" "<<min_y+(bok_y/2)<<" "<<((bok_x-1)/2+1);
        return 0;
    }
    if(bok_x==bok_y){
        cout<<min_x+(bok_x/2)<<" "<<min_y+(bok_y/2)<<" "<<((bok_x-1)/2+1);
        return 0;
    }
}
 