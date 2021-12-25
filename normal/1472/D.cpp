#include <bits/stdc++.h> 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define int long long
using namespace std;
void solve(){
    int n;
    scanf("%lld",&n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    vector<bool> vis(n+1,false);
    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        int curr = 0;
        if(vis[i]==false){
            vis[i] = true;
            curr+=a[i];
            int next = i+a[i];
            while(next<=n){
                curr+=a[next];
                vis[next] = true;
                next+=a[next];
            }
            ans = max(ans,curr);
        }
        
    }
    printf("%lld\n",ans);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%lld",&t);
    while(t--) solve();
    return 0;
}