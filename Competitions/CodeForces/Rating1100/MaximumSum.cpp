//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LL long long int

void solve(){
    int n,k;
    cin >> n >> k;

    long long int arr[n + 1];

    long long int sum = 0;

    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i <= k; i++){
        sum = max(sum, arr[n - i] - arr[(k - i) * 2]);
    }

    cout << sum << endl;
    return;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    

    int t;
    cin >> t;

    while(t --> 0 ){
        solve();
    }
    return 0;
}