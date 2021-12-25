// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    int mx_poss = (n*(n-1)/2)*3;
    vector<int> score(n);
    vector<vector<int>> res(n,vector<int>(n));
    if(mx_poss%n == 0){
        int mx = mx_poss/n,curr = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(score[i]<mx){
                    res[i][j] = 1;
                    score[i]+=3; 
                }else {
                    score[j]+=3;
                    res[i][j] = -1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cout << res[i][j] << " ";
            }
        }
        cout << endl;
    }else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = (j-i)*2;
                // cout <<":" << d << " ";
                if(d==n) cout << "0 ";
                else if(d<n) cout << "1 ";
                else cout << "-1 ";
            }
        }
        cout << endl;
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