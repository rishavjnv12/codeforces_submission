#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

template <typename T> vector<T> read_vector(int n) { vector<T> r(n); for (auto& a : r) cin >> a; return r; }
template <typename T> vector<T> read_vector() { int n; cin >> n; return read_vector<T>(n); }
int64_t ceil_div(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int64_t X, Y, K;
        cin >> X >> Y >> K;
        int64_t trades = ceil_div(K * Y + K - 1, X - 1);
        trades += K;
        cout << trades << '\n';
    }
    return 0;
}