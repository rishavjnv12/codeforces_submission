/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.01:08:56
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int team = 0;
    for(int first=0;first<=n;first++){
        if(2*first>m)
            break;
        int a = n-first,b = m-2*first;
        int second = min(a/2,b);
        team = max(team,first+second);
    }    
    cout << team << endl;
    return 0;
}