// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[3] = {0,0,0};
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            a[temp%3]++;
        }
        int ans = 0;
        n/=3;
        while(a[0]!=a[1] or a[1]!=a[2] or a[0]!=a[3]){
            if(a[0]<n){
                ans++;
                a[0]++;
                a[2]--;
            }
            if(a[1]<n){
                ans++;
                a[1]++;
                a[0]--;
            }
            if(a[2]<n){
                ans++;
                a[2]++;
                a[1]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}