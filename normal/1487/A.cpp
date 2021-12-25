// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    sort(a.begin(),a.end());
    int mn = a[0];
    int cnt = 0;
    for(int x:a){
        if(x == mn) cnt++;
    }
    cout << n - cnt << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}