/* author: gigawhiz */ 
#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 ll bigMod(ll  a, ll  b, ll c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    } 
 
    // Returns: (a * b/2) mod c
    ll a2 = bigMod(a, b / 2, c);
 
    // Even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2 + a2) % c;
    } else {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}
vector<ll> v(200011,0ll);
void calc(){
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 1;
    v[5] = 1;
    v[6] = 1;
    v[7] = 1;
    v[8] = 1;
    v[9] = 1;
    v[10] = 2;
    for(ll i=11;i<=200010;i++){
        v[i] = (v[i-10] + v[i-9])%MOD;
    }
}
int main()
{
    calc();
    ll t;
    cin>>t;
    while(t--){
        string a;
        ll b;
        cin>>a>>b;
        ll ans = 0;
        map<ll,ll> mp;
        for(ll i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(auto x:mp){
            if(mp[x.first]!=0){
                ans += bigMod(x.second,v[x.first-'0'+b],MOD);
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}