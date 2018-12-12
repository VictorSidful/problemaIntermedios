#include <bits/stdc++.h>
using namespace std;
int num;
int binary(int x){
int ini=1, fin = sqrt(num), mid;

  while(ini <= fin ){
    mid= 0.5*(ini+fin);
    int res = 0.5*(mid*(mid+1));
      if(res == x ) return 1;
      else if(res < x) ini= mid+1;
      else fin=mid-1;
  }
  return 0;
}

int main(){
  cin>>num;
  int res=0;
  for(int i=1;i <= sqrt(num*2); i++){
    res = binary( num - (i*(i+1))*0.5 );
    if(res) break;
  }
    if(res == 1) cout<<"YES\n";
    else cout<<"NO\n";

  return 0;
}
