#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(__builtin_popcountll(n)==1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}