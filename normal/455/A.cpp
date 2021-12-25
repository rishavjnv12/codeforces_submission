// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define vi vector<int>
#define pii pair<int,int> 
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    map<int,int> mp;
    for(int x:a) mp[x]++;
    vector<pair<int,int>> v;
    for(auto pp:mp) v.push_back(pp);
    n = v.size();
    vector<int> dp(1e5,0);
    dp[0] = 0;
    dp[1] = mp[1];
    for(int i=2;i<=1e5;i++)
        dp[i] = max(dp[i-1],dp[i-2]+(i*mp[i]));
    cout << dp[1e5] << endl;
}

int32_t main(){
    int t = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;
    while(t--) solve();
    return 0;
}