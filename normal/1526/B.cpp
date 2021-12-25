/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-29.20:04:50
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> pre;
    for(int i=0;i<=1000;i++)
        pre.push_back(111*i);
    while(t--){
        int n;
        cin >> n;
        string ans = "NO\n";
        for(int x:pre){
            if((n-x)>=0 and (n-x)%11==0){
                ans = "YES\n";
                break;
            }
        }
        cout << ans;
    }
    return 0;
}