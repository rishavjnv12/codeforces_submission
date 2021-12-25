#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
unordered_set<int> st;
void solve(){
    int n;
    cin >> n;
    if(n%2020==0 or n%2021==0){
        cout << "YES" << endl;
        return;
    }else{
        int found = false;
        int i=1;
        while(2021*i < n){
            if(st.count(n-2021*i)){
                found = true;
                break;
            }
            i++;
        }
        if(found){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

int32_t main(){
    for(int i=0;i<=495;i++){
        st.insert(2020*i);
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}