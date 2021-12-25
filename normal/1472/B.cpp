#include <bits/stdc++.h>
#define int long long
using namespace std;
void soolve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    int sum = accumulate(a.begin(),a.end(),0);
    if(sum&1){
        cout << "NO" << endl;
    }else{
        bool one = false;
        for(int x:a){
            if(x==1){
                one = true;
                break;
            }
        }
        if(((sum>>1)&1)==0)
            cout << "YES" << endl;
        else{
            if(one)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) soolve();
    return 0;
}