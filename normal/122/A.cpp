/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-29.23:38:40
***********************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%4==0 or n%7==0 or n%47==0 or n%74==0 or n%447==0 or n%477==0){
        puts("YES");
        return 0;
    }

    puts("NO");
    return 0;
}