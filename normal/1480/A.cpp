// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    string s;
    cin >> s;
    const int n = s.size();
    for(int i=0;i<n;i++){
        if(i%2 == 0){ // small
            if(s[i]=='a') s[i] = 'b';
            else s[i] = 'a';
        }else{
            if(s[i]=='z') s[i] = 'y';
            else s[i] = 'z';
        }
    }
    cout << s << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}