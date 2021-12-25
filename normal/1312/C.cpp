/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.12:18:02
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
void f(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    vector<int> v;
    int curr = 1;
    while(curr<=1e18){
        v.push_back(curr);
        curr *= k;
    }
    set<int> id;
    for(int &x:a){
        while(x){
            int idx = -1;
            for(int i=0;i<(int)v.size();i++){
                if(v[i]>x){
                    idx = i-1;
                    break;
                }
            }
            // cout << idx << " ";
            if(id.count(idx)){
                puts("NO");
                return;
            }else{
                id.insert(idx);
                x -= v[idx];
            }
        }
        // cout << endl;
    }
    puts("YES");

}

int32_t main(){
    int t;
    cin >> t;
    while(t--) f();
    return 0;
}