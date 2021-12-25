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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    if(k==0){
        cout << n << endl;
        return;
    }
    sort(all(a));
    int mex = -1;
    for(int i=0;i<n;i++){
        if(i!=a[i]){
            mex = i;
            break;
        }
    }
    if(mex == -1) mex = n;
    if(mex == n){
        cout << n+k << endl;
        return;
    }
    int mx = a.back();
    int ele = ((mex+mx+2-1)/2);
    if(binary_search(all(a),ele))
        cout << n << endl;
    else 
        cout << n+1 << endl;

}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}