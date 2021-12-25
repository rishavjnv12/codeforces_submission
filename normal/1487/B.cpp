// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    if(n&1){
        int over = (k-1)/(n/2);
        int ans = (k+over)%n?(k+over)%n:n;
        cout << ans << endl;
    }else{
        int ans = k%n?k%n:n;
        cout << ans << endl;
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