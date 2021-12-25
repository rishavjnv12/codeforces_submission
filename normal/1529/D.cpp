/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-25.10:29:47
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int32_t main(){
    int n;
    cin >> n;
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = 0;
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i)
            dp[j]++;
    }
    int pref = 1;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = (dp[i]+pref) % mod;
        pref = (pref+dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}