#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
const int mx = 1e5+5;
using namespace std;

int32_t main(){
    int t,k;
    cin >> t >> k;
    int dp[mx];
    for(int i=0;i<mx;i++){
        if(i>=k)
            dp[i] = (dp[i-1]+dp[i-k])%mod;
        else dp[i] = 1;
    }   
    for(int i=0;i<mx;i++){
        dp[i] = (dp[i-1]+dp[i]) % mod;
    }
    while(t--){
        int u,v;
        cin >> u >> v;
        cout << (dp[v]-dp[u-1]+mod)%mod << "\n";
    }
    return 0;
}