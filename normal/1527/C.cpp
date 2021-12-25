/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-21.20:40:36
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x:a)
            cin >> x;
        vector<int> dp(n,0);
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i)
                dp[i] = dp[i-1];
            dp[i] += mp[a[i]];
            mp[a[i]] += (i+1);
            ans += dp[i];
        }
        cout << ans << "\n";
    }
    return 0;
}