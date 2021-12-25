/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-16.19:30:52
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if((a+b+c)%9){
            cout << "NO\n";
        }else if(min({a,b,c})>=(a+b+c)/9){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}