/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-10-12.13:24:27
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x:a)
		cin >> x;
	sort(a.begin(),a.end());
	int ans = 0;
	for(int i=0;i<n;i++){
		int total = upper_bound(a.begin()+i,a.end(),a[i]+2) - (a.begin()+i) - 1;
		ans += (total*(total-1))/2;
	}
	cout << ans << "\n";
	
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
    return 0;
}
// 1 2 3 4