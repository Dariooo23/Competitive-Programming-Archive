//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

void solve(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (n == 1){
        cout << 1 << endl;
        return;
    }
    if (n == 2){
        if (arr[0] == arr[1]){
            cout << 1 << endl;
            return;
        } else {
            cout << 2 << endl;
            return;
        }
    }

    int b = n;
    int start = 0;
    int end = 2;
    while (end < n){
        if (arr[start] <= arr[end - 1] && arr[end - 1] <= arr[end]){
            b--;
            end++;
        }else{
            if (arr[start] >= arr[end - 1] && arr[end - 1] >= arr[end]){
                b--;
                end++;
            }else{
                start = end - 1;
                end++;
            }
        }
    }

    if (start == 0 && end == n && arr[start] == arr[end - 1]){
        b--;
    }

    cout << b << endl;
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t --> 0){
        solve();
    }
    return 0;
}