#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int mx = 0;
    for(int y:a) mx+=ceil(1.0*y/x);
    int mn = 0;
    int curr = 0;
    for(int y:a){
        if(curr%x == 0){
            mn+=(curr/x);
            curr = y;
        }else{
            curr+=y;
        }
    }
    mn+=ceil(1.0*curr/x);
    cout << mn << " " << mx << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}