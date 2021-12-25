// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int A,B,n;
    cin >> A >> B >> n;
    vector<int> a(n),b(n);
    for(int &x:a)
        cin >> x;
    for(int &x:b)
        cin >> x;
    int t = 0;
    for(int i=0;i<n;i++){
        int fight = (b[i]+A-1)/A;
        B -= (fight*a[i]);
        t+=fight;
    }
    if(B>=0)
        puts("YES");
    else{
        int mx = *max_element(a.begin(),a.end());
        B+=mx;
        if(B>=0)
            puts("YES");
        else 
            puts("NO");
    }
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}