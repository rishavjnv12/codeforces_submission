/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.01:18:26
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a){
        cin >> x; 
    }   
    for(int &x:a){
        while(x%2==0) x/=2;
        while(x%3==0) x/=3;
    }
    cout << (set<int>(a.begin(),a.end()).size()==1?"YES":"NO") << endl;
    return 0;
}