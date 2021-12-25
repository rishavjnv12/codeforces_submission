/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-10-12.13:35:45
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int fact[200005];
const int mod = 1e9+7;
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
int nck(int n,int r){
    if(n<r)
        return 0;
    if(r==0)
        return 1;
    return (fact[n] *modInverse(fact[r],mod)%mod*modInverse(fact[n - r], mod) % mod)% mod;
}
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    sort(a.begin(),a.end());
    int ans = 0;
	for(int i=0;i<n;i++){
		int total = upper_bound(a.begin()+i,a.end(),a[i]+k) - (a.begin()+i) - 1;
		ans = (ans + nck(total,m-1)) % mod;
	}
    cout << ans << "\n";
}
void pre(){
    fact[0] = 1;
    for(int i=1;i<=200004;i++)
        fact[i] = (fact[i-1]*i) % mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}