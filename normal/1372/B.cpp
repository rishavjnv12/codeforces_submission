/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.00:41:48
***********************************************/
#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            int clcm = n-1;
            int a = 1;
            for(int i=1;i*i<=n;i+=2){
                if(n%i == 0){
                    if(lcm(i,n-n/i)<clcm){
                        clcm = lcm(i,n-n/i);
                        a = i;
                    }
                }
            }
            cout << a << " " << n-a << endl;
        }else{
            cout << n/2 << " " << n/2 << endl;
        }
    }
    return 0;
}