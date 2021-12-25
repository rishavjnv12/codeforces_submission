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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int &x:a) cin >> x;
    int ans = 0;
    for(int x:a){
        if(5-x>=k) ans++;
    }
    cout << round(ans/3.0) << endl;
    
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}