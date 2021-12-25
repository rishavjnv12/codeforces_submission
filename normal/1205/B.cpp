// AUTHOR :- RISHAV KUMAR
// ERRICHTO STREAM
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
    vector<int> a(n);
    for(int &x:a) cin >> x;
    
    vector<int> bits(60);
    for(int x:a){
        if(x == 0)
            continue;
        for(int i=0;i<60;i++){
            if(x&(1LL<<i)){
                bits[i]++;
            }
            if(bits[i]>=3){
                cout << "3\n" << endl;
                return;
            }
        }
    }
    if(n>120){
        cout << "-1\n" << endl;
        return;
    }
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]&a[j]){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans = INT_MAX;
    
    assert(n<120);
    for(int start=0;start<n;start++){
        vector<int> dist(n,-1),parent(n,-1);
        dist[start] = 0;
        vector<int> q(1,start);
        for(int i=0;i<(int)q.size();i++){
            int node = q[i];
            for(int b:g[node]){
                if(dist[b]==-1){
                    dist[b] = dist[node]+1;
                    parent[b] = node;
                    q.push_back(b);
                }else if(parent[node]!=b){
                    ans = min(ans,dist[node]+dist[b]+1);
                }
            }
        }
    }

    if(ans==INT_MAX)
        cout << "-1\n";
    else cout << ans << endl;
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