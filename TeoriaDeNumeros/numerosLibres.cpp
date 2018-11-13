#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main(){
int N;cin>>N;

while(N--){
 i64 a,b;cin>>a>>b;
    if(__gcd(a,b) == 1)
	cout<<"SI\n";
    else cout<<"NO\n";
}
 return 0;
}