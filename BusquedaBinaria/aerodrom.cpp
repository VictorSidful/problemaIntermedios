#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

vector<i64> tiempos(300005);

i64 operacion(i64 n,i64 desk){
 i64 res=0;
   for(i64 i=0; i<desk;i++){
     res+=n/tiempos[i];
   }
   return res;
}

int main(){
 
  i64 desk,people;
  cin>>desk>>people;
  i64 max=0;	
  for(int i=0;i<desk;i++){
    int tiempo;cin>>tiempo;
    tiempos[i]=tiempo;
    if(tiempo>max) max= tiempo;
  }

  i64 ini=0,fin=max*people,mid; 	
  while(ini < fin){
     mid= 0.5*(ini+fin);
     if(operacion(mid,desk) < people)
       ini=mid+1;
     else
  	fin=mid;
  }
  cout<<ini;
 return 0;
}