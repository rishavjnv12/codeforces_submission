#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(vector<pair<int,int>> &v,int idx){
    int token = v[idx].first;
    for(int i=0;i<v.size();i++){
        if(i!=idx){
            if(token<v[i].first)
                return false;
            token+=v[i].first;
        }
    }
    return token > 0;
}
void s(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(v,mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    if(ans==-1){
        puts("0");
        return;
    }
    set<int> st;
    for(int i=ans;i<n;i++){
        st.insert(v[i].second);
    }
    cout << st.size() << endl;
    for(int x:st)
        cout << x+1 << " ";
    cout << "\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--) s();
}