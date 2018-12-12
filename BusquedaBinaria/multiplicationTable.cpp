#include<bits/stdc++.h>
using namespace std ;
long long n,m,query;

long long binary(long long ini, long long fin){
  long long mid=0;
  long long res=0;

  while(ini < fin){
    res=0;
    mid= 0.5*(ini+fin);
    for(long long i = 1; i <=n;i++ ){
      res +=  min(mid/i,m);
    }
    if (res < query ) ini=mid+1;
    else  fin=mid;
  }
  return fin;
}

int main(){
    cin>>n>>m>>query;
    long long z = n*m;

    long long res = binary(1,z);
    cout<<res<<"\n";
  return 0;
}
