/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.01:00:41
***********************************************/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) 
        cin >> x;
    auto b = a;
    sort(b.begin(),b.end());
    int mn = INT_MAX;
    for(int x:a)
        mn = min(mn,x);
    for(int i=0;i<n;i++){
        if(a[i]!=b[i] and a[i]%mn){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}