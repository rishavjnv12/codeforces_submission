/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-01.20:40:28
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    for(auto &s:a)
        cin >> s;

    int ans = 0;
    int i = 0,j = 0;
    while(true){
        if(a[i][j]=='*') ans++;
        if(i==h-1 and j==w-1)
            break;
        if(i==h-1){
            j++;
            continue;
        }else if(j==w-1){
            i++;
            continue;
        }
        if(i==h-1 and j==w-1)
            break;
        if(a[i][j+1]=='*'){
            j++;
        }else if(a[i+1][j]=='*'){
            i++;
        }else{
            j++;
        }
        if(i==h-1 and j==w-1)
            break;
    }
    cout << ans << endl;
    return 0;
}