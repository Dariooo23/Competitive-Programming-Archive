//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

void wersja_string(int n){
    string nazwiska[n];

    for (int i = 0; i < n; i++){
        cin >> nazwiska[i];
    }

    for (int i = 0; i < n; i++){
        cout << nazwiska[i] << endl;
    }

    return;
}

void wersja_c(int n){
    char** nazwiska = new char*[n];

    for (int i = 0; i < n; i++){
        char nazwisko[100];
        char znak;
        int j = 0;

        while (znak != '\n'){
            cin >> znak;
            nazwisko[j] = znak;
            j++;
        }

        nazwiska[i] = new char[j + 1];
        for (int k = 0; k < j; k++){
            nazwiska[i][k] = nazwisko[k];
        }nazwiska[i][j] = '\0';
    }

    for (int i = 0; i < n; i++){
        cout << nazwiska[i] << endl;
    }
    
    for (int i = 0; i < n; i++){
        delete[] nazwiska[i];
    }delete[] nazwiska;
    nazwiska = nullptr;

    return;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    wersja_string(n);
    wersja_c(n);

    return 0;
}
