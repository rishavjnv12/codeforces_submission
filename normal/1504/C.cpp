/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-04.12:37:53
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        string s;cin >> s;
        
        
        vector<int> one,zero;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero.push_back(i);
            else one.push_back(i);
        }
        int o = one.size(),z = zero.size();
        if(s[0]=='0' or s.back()=='0' or z&1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string x(n,' '),y(n,' ');
        int i=0,j=(int)one.size()-1;
        while(i<j){
            y[one[i]] = x[one[i]] = '(';
            y[one[j]] = x[one[j]] = ')';
            i++,j--;
        }
        int move = 1;
        for(int idx:zero){
            if(move){
                x[idx] = '(';
                y[idx] = ')';
            }else{
                y[idx] = '(';
                x[idx] = ')';
            }
            move ^= 1;
        }
        for(int i=0;i<n;i++){
            assert(x[i]!=' ');
            assert(y[i]!=' ');
        }
        cout << x << "\n" << y << "\n";
    }
    return 0;
}