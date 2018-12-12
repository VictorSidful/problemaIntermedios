#include<bits/stdc++.h>
using namespace std;
double p,q,r,s,t,u;
const double cons= 1e-8;

double func(double x){
  return  p*(exp(-x))+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double binary(){
  double ini=0,fin=1,mid,res=0,r;

  for(int i=0;i<30;i++){
    mid=0.5*(ini+fin);
    r=func(mid);

      if(r>0){
       ini = mid;
       res=mid;
      }else{
        fin=mid;
      }
  }
  return res;
}

int main(){

  while(cin>>p>>q>>r>>s>>t>>u){

    if(func(0)*func(1) > 0) printf("No solution\n");
    else printf("%.4lf\n",binary());

  }
  return 0;
}
