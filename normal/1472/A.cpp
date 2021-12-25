#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int w,h,n;
    cin >> w >> h >> n;
    int x = 0,y=0;
    while((w&1) == 0){
        x++;
        w>>=1;
    }
    while((h&1)==0){
        y++;
        h>>=1;
    }
    int pos = (1<<x)*(1<<y);
    if(pos>=n) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}