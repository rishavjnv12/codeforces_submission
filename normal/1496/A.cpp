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
    string s;
    cin >> s;
    if(k == 0){
        puts("YES");
        return;
    }
    if(n%2==0 and k == n/2){
        puts("NO");
        return;
    }
    string nor = string(s.begin(),s.begin()+k);
    string rev = string(s.rbegin(),s.rbegin()+k);
    // cout << nor << " " << rev << endl;
    if(nor == rev)
        puts("YES");
    else puts("NO");
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}