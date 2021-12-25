//Adarsh Singh Kushwaha
#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
int dp[5005][5005];
int cal(vector<int> one,vector<int> zero,int n,int m,int i,int j){
    if(i==n){
        return 0;
    }
    if(j==m){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=min(abs(one[i]-zero[j])+cal(one,zero,n,m,i+1,j+1),cal(one,zero,n,m,i,j+1));
    return dp[i][j];
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    memset(dp,-1,sizeof(dp));
    vector<int> one,zero;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]){
            one.push_back(i);
        }else{
            zero.push_back(i);
        }
    }
    int x=cal(one,zero,one.size(),zero.size(),0,0);
    cout<<x<<"\n";
    return 0;
}