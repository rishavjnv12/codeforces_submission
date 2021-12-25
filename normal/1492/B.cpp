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
    vi a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    vector<int> vis(n+1,false);
    int last = n-1;
    vector<int> ans;
    for(int mx = n;mx>=1;mx--){
        if(vis[mx])
            continue;
        else{
            for(int j=mp[mx];j<=last;j++){
                vis[a[j]] = true;
                ans.push_back(a[j]);
            }
            last = mp[mx]-1;
        }
    }
    for(int x:ans){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}