// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void rec(vector<int> &a,int l,int r,int h){
    if(l>r)
        return;
    int mx = a[l];
    int mx_id = l;
    for(int i=l;i<=r;i++){
        if(a[i]>mx){
            mx_id = i;
            mx = a[i];
        }
    }
    a[mx_id] = h;
    rec(a,l,mx_id-1,h+1);
    rec(a,mx_id+1,r,h+1);
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int h = 0;
    for(int &x:a) cin >> x;
    rec(a,0,n-1,0);
    for(int x:a)
        cout << x << " ";
    cout << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}