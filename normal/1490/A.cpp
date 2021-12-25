// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
int f(int a,int b){
    if(a>b) swap(a,b);
    int x = a;
    int ans = 0;
    while(true){
        if(b<=2*x)
            break;
        x*=2;
        ans++;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int x = a[0];
    int ans = 0;
    for(int i=1;i<n;i++){
        ans+=f(a[i-1],a[i]);
    }
    cout << ans << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << f(10,1) << endl;
    cin >> t;
    while(t--) solve();
    return 0;
}