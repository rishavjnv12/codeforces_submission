// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
int n;
using namespace std;
vector<int> arr;
int query(int i){
    if(arr[i]!=-1)
        return arr[i];
    cout << "? " << i << endl;
    fflush(stdout);
    cin >> arr[i];
    return arr[i];
}
void solve(){
    cin >> n;
    arr.resize(n+2,-1);
    arr[0] = INT_MAX;
    arr[n+1] = INT_MAX; 
    int _l = 1,r = n;
    while(_l<=r){
        int mid = (_l+r)/2;
        int j = query(mid-1);
        int k = query(mid);
        int l = query(mid+1);
        // cout << mid << j << k << l << endl;
        if(k < j and k < l){
            cout << "! " << mid << endl;
            return;
        }else if(k<j){
            _l = mid+1;
        }else{
            r = mid-1;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}