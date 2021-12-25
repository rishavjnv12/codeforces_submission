// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int i;
    int x = a.back();
    int total = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(j==n-1){
                puts("-1");
                return;
            }
            if(a[j]<a[j+1]){
                a[j]++;
                if(i==k-1){
                    cout << j+1 << endl;
                    return;
                }
                break;
            }
        }
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