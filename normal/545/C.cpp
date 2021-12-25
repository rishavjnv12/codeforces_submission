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
    vector<int> h(n),a(n);
    for(int i=0;i<n;i++)
        cin >> a[i] >> h[i];
    int dp[n][2];
    dp[0][0] = a[0];
    dp[0][1] = 1;
    // dp[occupied][couhnt]
    for(int i=1;i<n;i++){
        if(dp[i-1][0]<a[i]-h[i]){
            dp[i][0] = a[i];
            dp[i][1] = dp[i-1][1]+1;
        }else if(dp[i-1][0]<a[i]){
            dp[i][0] = a[i]+h[i];
            dp[i][1] = dp[i-1][1]+1;
        }else{
            dp[i][0] = a[i]+h[i];
            dp[i][1] = dp[i-1][1];
        }
    }
    cout << dp[n-1][1] << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    t = 1;
    while(t--) solve();
    return 0;
}