/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-01.19:54:26
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size()<=10){
            cout << s << "\n";
        }else{
            cout << string(1,s[0])+to_string(s.size()-2)+string(1,s.back()) << endl;
        }
    }
    return 0;
}