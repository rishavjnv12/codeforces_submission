/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-16.19:40:02
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &x:a){
			cin >> x;
		}

		for(int i=0;i<n;i++){
			int x = 1;
			while(x*2<=a[i]) x*=2;
			cout << x << " ";
		}
		cout << "\n";
		

	}
    return 0;
}