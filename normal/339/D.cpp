#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> a(1<<n);
    for(int &x:a)
        cin >> x;
    vector<vector<int>> tree(1,a);
    int move = 1;
    while(a.size()>1){
        vector<int> here;
        for(int i=0;i<a.size();i+=2){
            if(move){
                here.push_back(a[i]|a[i+1]);
            }else{
                here.push_back(a[i]^a[i+1]);
            }
        }
        tree.push_back(here);
        a = here;
        move ^= 1;
    }
    // for(auto &v:tree){
    //     for(int x:v){
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    while(q--){
        int i,x;
        cin >> i >> x;
        i--;
        tree[0][i] = x;
        i /= 2;
        int move = 1;
        for(int l=1;l<=n;l++){
            if(move){
                tree[l][i] = tree[l-1][i*2] | tree[l-1][i*2+1];
            }else{
                tree[l][i] = tree[l-1][i*2] ^ tree[l-1][i*2+1];
            }
            i /= 2;
            move ^= 1;
        }
        // cout << "\n\n";
        // for(auto &v:tree){
        //     for(int x:v){
        //         cout << x << " ";
        //     }
        //     cout << "\n";
        // }
        cout << tree[n][0] << "\n";
    }
    return 0;
}


// 0 1 2 3 4 5 6 7
// 0 1 2 3     (0,1)->0, (2,3)->1, (4,5)->2