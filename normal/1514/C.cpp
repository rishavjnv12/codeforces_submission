/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-19.22:35:22
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cin >> n;
	set<int> st;
	int prod = 1;
	for(int i=1;i<n;i++)
		if(__gcd(i,n)==1){
			st.insert(i);
			prod = (prod * i) % n;
		}
	if(prod != 1)
		st.erase(prod);
	cout << st.size() << "\n";
	for(int x:st)
		cout << x << " ";
	cout << "\n";
    return 0;
}