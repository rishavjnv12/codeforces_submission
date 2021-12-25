// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),a.end()
#define pb push_back
#define vi vector<int>
#define pii pair<int,int> 
#define nl '\n'
const int mod = 1e9+7;
using namespace std;
int upto(int x){
    if(!x)
        return 0;
    return (x*(x+1))/2;
}
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int &x:a) cin >> x;
    int sum = accumulate(all(a),0LL);
    int curr = 0;
    for(int i=0;i<n;i++){
        curr += a[i];
        if(curr<upto(i)){
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}