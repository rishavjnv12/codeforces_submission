// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define vi vector<int>
#define pii pair<int,int> 
#define float long double
const int mod = 1e9+7;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long double> aadmi,khajana;
    for(int i=0;i<2*n;i++){
        int x,y;
        cin >> x >> y;
        if(x == 0)
            aadmi.push_back(abs(y));
        else khajana.push_back(abs(x));
    }
    sort(all(aadmi));
    sort(all(khajana));
    float ans = 0;
    for(int i=0;i<n;i++){
        ans = ans + hypot(aadmi[i],khajana[i]);
    }
    printf("%.9Lf\n",ans);
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) solve();
    return 0;
}