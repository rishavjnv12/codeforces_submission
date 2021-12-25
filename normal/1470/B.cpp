/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-09.12:10:41
***********************************************/
#include <bits/stdc++.h>
using namespace std;


const int mx = 1e6+5;
vector<int> spf(mx+1,-1);
void seive(){
    spf[1] = 1; 
    for(int i=2;i<=mx;i++){
        if(spf[i]==-1){
            for(int j=1;i*j<=mx;j++){
                if(spf[i*j]==-1)
                    spf[i*j] = i;
            }
        }
    }
}

int get_repr(int n){
    int ans = 1;

    while(n!=1){
        int sp = spf[n];
        int cnt = 0;
        while(n%sp==0){
            n/=sp;
            cnt++;
        }
        if(cnt&1)
            ans*=sp;
    }
    return ans;
}

int main(){
    seive();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        vector<int> mp(mx+5);
        for(int &x:a){
            scanf("%d",&x);
            int y = get_repr(x);
            mp[y]++;
        }
        int q;
        scanf("%d\n",&q);
        int mx = 0;
        for(auto &p:mp)
            mx = max(mx,p);
        for(int i=1;i<=mx;i++){
            if(i==1)
                continue;
            if(mp[i]%2==0){
                mp[1] += mp[i];
                mp[i] = 0;
            }
        }

        int mx2 = 0;
        for(auto &p:mp)
            mx2 = max(mx2,p);
        while(q--){
            int x;
            scanf("%d",&x);
            if(!x)
                printf("%d\n",mx);
            else{
                printf("%d\n",mx2);
            }
        }
    }
    return 0;
}