// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
unordered_set<int> st;
void solve(){
    int x;
    cin >> x;
    for(int i=1;i<=10001;i++){
        int target = x-(i*i*i);
        if(st.count(target)){
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int32_t main(){
    for(int i=1;i<=10005;i++)
        st.insert(i*i*i);
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}