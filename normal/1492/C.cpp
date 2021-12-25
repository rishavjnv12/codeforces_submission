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
int find_wid(vi &v){
    int ans = 0;
    const int n = v.size();
    for(int i=1;i<n;i++)
        ans = max(ans,v[i]-v[i-1]);
    return ans;
}
void solve(){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a;
    cin >> b;
    vector<vi> idx(26);
    vector<int> ptr(26,0);
    for(int i=0;i<n;i++){
        idx[a[i]-'a'].push_back(i);
    }
    vi left(m),right(m);
    for(int i=0;i<m;i++){
        int c = b[i]-'a';
        if(i==0){
            left[i] = idx[c][ptr[c]];
            ptr[c]++;
        }else{
            while(idx[c][ptr[c]]<=left[i-1]){
                ptr[c]++;
            }
            left[i] = idx[c][ptr[c]];
            ptr[c]++;
        }
    }
    for(int i=26;~i;i--){
        ptr[i] = idx[i].size()-1;
    }
    for(int i=m-1;~i;i--){
        int c = b[i]-'a';
        if(i==m-1){
            right[i] = idx[c][ptr[c]];
            ptr[c]--;
        }else{
            while(idx[c][ptr[c]]>=right[i+1]){
                ptr[c]--;
            }
            right[i] = idx[c][ptr[c]];
            ptr[c]--;
        }
    }
    int ans = 1;
    for(int i=1;i<m;i++){
        ans = max(ans,right[i]-left[i-1]);
    }
    cout << ans << "\n";
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}