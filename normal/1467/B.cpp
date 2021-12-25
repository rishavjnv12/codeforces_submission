#include <bits/stdc++.h> 
#define int int64_t
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n<=3){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    vector<int> h(n),v(n);
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i-1] and a[i]>a[i+1]){
            h[i] = 1;
            ans++;
        }else if(a[i]<a[i-1] and a[i]<a[i+1]){
            v[i] = 1;
            ans++;
        }
    }
    if(ans == 1 or ans==0){
        cout << 0 << endl;
        return;
    }
    // for(int x:h) cout << x << " ";
    // cout << endl;
    // for(int x:v) cout << x << " ";
    // cout << endl;
    bool t = false;
    // cout << ans << endl;
    for(int i=1;i<n-1;i++){
        if(h[i] and v[i-1] and v[i+1]){
            a[i] = a[i-1];
            t = true;
            break;
        }else if(v[i] and h[i-1] and h[i+1]){
            a[i] = a[i-1];
            t = true;
            ans-=3;
            break;
        }
    }
    if(!t){
        for(int i=0;i<n-1;i++){
            if((v[i] and h[i+1]) or (h[i] and v[i+1])){
                a[i+1] = a[i];
                ans-=2;
                t=true;
                break;
            }
        }
    }
    if(!t) {
        ans-=1;
        assert(ans>=0);
        cout << ans << endl;
    }
    ans = 0;
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i-1] and a[i]>a[i+1]){
            h[i] = 1;
            ans++;
        }else if(a[i]<a[i-1] and a[i]<a[i+1]){
            v[i] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}