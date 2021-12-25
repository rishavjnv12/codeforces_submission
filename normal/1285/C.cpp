/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.12:48:38
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}

int32_t main(){
    int x;
    cin >> x;
    int mx = x;
    vector<int> ans = {1,x};
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(lcm(i,x/i)==x and x/i<mx){
                mx = x/i;
                ans = {i,x/i};
            }
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}