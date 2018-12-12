#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int stock,cabReq;
vector<double> sizes;

int op(int x){
  int res=0;
  for(int i=0; i< stock;i++){
    res += (sizes[i]/x);
  }
  return res;
}

double binary(int fin){
  int res,mid,ini=1;

  while(ini < fin){
    mid= 0.5*(ini+fin);
    if( op(mid) >= cabReq){
      ini=mid+1;
      res=mid;
    }else{
      fin=mid;
    }
    //cout<<ini<<" <-> "<<fin<<"\n";
  }

  return 1.0*res/100;
}

int main(){
  int fin=0;
  cin>>stock>>cabReq;
  sizes = vector<double> (stock);
  for (int i = 0; i < stock; i++){
    cin>>sizes[i];
    sizes[i]*=100;
    fin+=sizes[i];
  }

  double res = binary(fin);
  if(res < 1) printf("0.00");
  else printf("%.2lf",res );
  return 0;
}
