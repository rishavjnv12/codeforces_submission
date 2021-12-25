#include <bits/stdc++.h>
using namespace std;
int main(){
    long long r,g,b;
    cin >> r >> g >> b;
    long long sum = (r+g+b);
    long long ans = 0;
    for(long long x:{r,g,b}){
        if((sum-x)>=2*x)
            ans = max(ans,x);
    }
    cout << ans << "\n";
    return 0;
}