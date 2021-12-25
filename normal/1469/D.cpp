// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    cout << n-1 << endl;
    cout << n << " " << n-1 << endl;
    for(int i=1;i<=n-2;i++){
        cout << i << " " << n-1 << endl;
    }
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}