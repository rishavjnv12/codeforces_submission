/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-10-12.18:23:35
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int mod = 1e9+7;
    int n,l,r;
    cin >> n >> l >> r;
    int cnt[3];
    for(int i:{0,1,2}){
        cnt[i] = r/3 - l/3 + (l%3 == 0);
        l++,r++;
    }
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0] = {cnt[0],cnt[1],cnt[2]};
    for(int i=1;i<n;i++){
        dp[i][0] = (dp[i-1][0]*cnt[0]+dp[i-1][1]*cnt[2]+dp[i-1][2]*cnt[1])%mod;
        dp[i][1] = (dp[i-1][0]*cnt[1]+dp[i-1][1]*cnt[0]+dp[i-1][2]*cnt[2])%mod;
        dp[i][2] = (dp[i-1][0]*cnt[2]+dp[i-1][1]*cnt[1]+dp[i-1][2]*cnt[0])%mod; 
    }
    cout << dp[n-1][0] << "\n";
    return 0;
}