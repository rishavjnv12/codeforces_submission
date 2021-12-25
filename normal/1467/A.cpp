#include <bits/stdc++.h>
using namespace std;
int ne(int x){
    return x==9?0:x+1;
}
char ne(char c){
    return c=='9'?'0':c+1;
}
void s(){
    int n;
    cin >> n;
    if(n==1){
        cout << 9 << endl;
        return;
    }
    if(n==2){
        cout << 98 << endl;
        return;
    }
    vector<int>ans(n);
    ans[0] = 9;
    ans[1] = 8;
    for(int i=2;i<n;i++){
        ans[i] = ne(ans[i-1]);
    }
    for(int x:ans) cout << x;
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) s();
    return 0;
}