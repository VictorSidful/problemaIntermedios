#include <bits/stdc++.h>
using namespace std;
vector<int> establos;

int n,cows;

int func(int x){
  int actual=establos[0];
  int res=1;
  for(int i=1;i<n;i++){
    if(establos[i]-actual >= x){
      res++;
      actual = establos[i];
    }
  }
  return res;
}

int binary(int ini, int fin){
int mid=0,res;

  while(ini <= fin){
    mid=0.5*(ini+fin);
    if(func(mid) < cows){
      fin = mid-1;
    }else{
      res = mid;
      ini=mid+1;
    }
  }
  return res;
}

int main(){

  int cases; cin>>cases;
  while (cases--) {
    cin>>n>>cows;
    establos = vector<int> (n);
    for(int i=0;i<n;i++) cin>>establos[i];

    sort(establos.begin(),establos.end());

    int res = binary(0,establos[n-1]);

    cout<<res<<"\n";
  }
  return 0;
}
