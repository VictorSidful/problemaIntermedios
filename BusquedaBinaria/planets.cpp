#include <bits/stdc++.h>
using namespace std;

vector <double> planetas;
int N;

double ecuacion(double a){
  double res=0;
	for(int i=0;i<N;i++)
    res += 1/(planetas[i]-a);
 return res;
}

double binary(double ini, double fin){
 double mid;
    int i=0;
    while(i < 25){
      mid= 0.5*(ini+fin);
       if( ecuacion(mid) > 0 ){
          fin = mid;
       }else{
          ini = mid;
       }
    i++;
	 }
   return ini;
}

int main(){
  cin>>N; planetas = vector<double> (N);
	for(int i=0;i<N;i++)
      cin>>planetas[i];
  sort(planetas.begin(),planetas.end());
  cout.precision(3);
  cout<<"\n"<<(N-1)<<"\n";
  for(int i=0; i<N-1;i++){
	 double resultado = binary(planetas[i],planetas[i+1]);
	 cout<<fixed<<resultado<<" ";
  }
}
