// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>
#define pii pair<int,int> 
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vi x(n),y(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    sort(all(x));
    sort(all(y));
    cout << (x[n/2]-x[(n-1)/2]+1)*(y[n/2]-y[(n-1)/2]+1) << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}