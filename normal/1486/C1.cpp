// AUTHOR :- RISHAV KUMAR
#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),a.end()
#define pb push_back
#define vi vector<int>
#define pii pair<int,int> 
const int mod = 1e9+7;
int n;
using namespace std;
map<pair<int,int>,int> mp;
int query(int l,int r){
    if(mp.count({l,r}))
        return mp[{l,r}];
    printf("? %lld %lld\n",l,r);
    fflush(stdout);
    int idx;
    scanf("%lld",&idx);
    return mp[{l,r}] = idx;
}
void solve(){
    
    cin >> n;
    int l=1,r=n;
    while(l<=r){
        if(l==r){
            printf("! %lld\n",l);
            break;
        }else if(r-l==1){
            int idx = query(l,r);
            if(idx == l){
                printf("! %lld\n",r);
                break;
            }else{
                printf("! %lld\n",l);
                break;
            }
        }
        int idx = query(l,r);
        if(idx == l){
            int mid = (l+r)/2;
            int idx1 = query(l,mid);
            int idx2 = query(mid,r);
            if(idx1!=idx){
                l = mid;
            }else{
                r = mid;
            }
            continue;
        }
        if(idx == r){
            int mid = (l+r)/2;
            int idx1 = query(l,mid);
            int idx2 = query(mid,r);
            if(idx2!=idx){
                r = mid;
            }else{
                l = mid;
            }
            continue;
        }
        int ll = query(l,idx);
        int rr = query(idx,r);
        if(ll==idx){
            r = idx-1;
        }else{
            l = idx+1;
        }
    }
    // cout << l << " " << r << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}