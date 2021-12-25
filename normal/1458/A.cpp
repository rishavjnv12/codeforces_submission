#include <bits/stdc++.h>
#define int long long
using namespace std;

//Compiler version g++ 6.3.0

signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1){
      int x;
      scanf("%d",&x);
      while(m--){
        int q;
        scanf("%d",&q);
        printf("%d ",x+q);
      }
      return 0;
    }
    vector<int> a(n);
    for(int &x:a) 
        scanf("%d",&x);
    int g  = 0;
    for(int i=1;i<n;i++)
      g = __gcd(g,a[i]-a[i-1]);
      
    while(m--){
      int q;
      scanf("%d",&q);
      int ans =  __gcd(g,q+a[0]) ;
      printf("%d ",abs(ans));
    }
    return 0;
}