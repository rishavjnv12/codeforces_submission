#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>ar(n);
        for(int i=0;i<n;++i)
            cin>>ar[i];
        if(n == 1)
            printf("1");
        bool all_equal  = true;
        for(int i=1;i<n;i++){
            if(ar[i] !=ar[i-1]){
                all_equal = false;
                break;
            }
        }
        if(all_equal)
            printf("-1\n");
        else{
            int mx = *max_element(ar.begin(),ar.end());
            if(ar[0] == mx and ar[0] > ar[1])
                printf("1\n");
            else{
                bool flag = true;
                for(int i = 0;i<n-1;i++){
                    if(ar[i] == mx and ar[i+1]!=mx){
                        printf("%d\n",i+1);
                        flag = false;
                        break;
                    }
                }
                if(flag == false)
                    continue;
                for(int i = 1;i < n;i++){
                    if(ar[i] == mx and ar[i-1]!=mx){
                        printf("%d\n",i+1);
                        break;
                    }
                }
            }

        }
    }
    return 0;
}