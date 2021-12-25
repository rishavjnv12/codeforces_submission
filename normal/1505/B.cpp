#include <bits/stdc++.h>
using namespace std;
int f(int n){
    int ans = 0;
    while(n){
        ans += (n%10);
        n/=10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    while(n>=10){
        n = f(n);
    }
    cout << n << endl;
    return 0;
}