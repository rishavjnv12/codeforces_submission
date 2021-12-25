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

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n),pos(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        for(int i=0; i<n; i++){
            cin>>pos[i];
        }

        vector<int> unl;
        for(int i=0; i<n; i++){
            if(!pos[i])
                unl.push_back(v[i]);
        }
        sort(unl.begin(), unl.end(),greater<int>());
        int x = 0;
        for(int i=0;i<n;i++){
            if(!pos[i]){
                v[i]=unl[x];
                x++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}