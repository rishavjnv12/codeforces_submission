// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int x,y;
    cin >> x >> y;
    int a = 0,b = 0;
    string s;
    cin >> s;
    bool x_found = false,y_found = false;
    int u = 0,d = 0,l = 0,r = 0;
    for(char c:s){
        if(c == 'U') u++;
        if(c == 'D') d++;
        if(c == 'L') l++;
        if(c == 'R') r++;
    }
    if(x>=0 and r>=x) x_found = true;
    if(x<0 and l>=abs(x)) x_found = true;
    if(y>=0 and u>=y) y_found = true;
    if(y<0 and d>=abs(y)) y_found = true;
    if(x_found and y_found)
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