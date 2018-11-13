#include <bits/stdc++.h>
#define dig 1000
using namespace std;

vector <float> planetas;
vector<float> valores;
int N;

float ecuacion(float a){
    float res=0;
	for(int i=0;i<N;i++) res+=(1/(planetas[i]-a));         
 return res; 
}

float binary(float digito){
 int res=-1,mid,ini=0,fin=valores.size()-1;float menor=dig+1;
   
    while(ini<=fin){ 	
     mid= 0.5*(ini+fin);

     float total; total = ecuacion(digito+valores[mid]);
	 if(total == 0){
	  res =mid;  fin =mid-1; menor = 0;
	 }
	 if(total > 0){
		if(total<0) total = total*-1;	
	 	if(total < menor){ res= mid; menor = total;} 
	 fin = mid-1;
	 }
	if(total < 0){ if(total<0) total = total*-1;
	 	if(total < menor){res= mid; menor = total;}
	 ini = mid+1;
	}
    }
   return (digito+valores[res]);
}

int main(){
  	cin>>N;
        planetas = vector<float> (N);
	for(int i=0;i<N;i++) cin>>planetas[i];

	valores = vector<float> (dig);
	for(float i=0;i<dig;i++) valores[i]= i/dig;
	int x=0,n=N-1;
	cout<<n<<"\n";
	while(n--){
	   int tam = planetas[x+1]-planetas[x];
	   float res,r=dig,resultado,aux;
	   for(float i=0;i<tam;i++){
	       res= binary(planetas[x]+i);
	       aux= ecuacion(res);
	       if(aux < 0) aux = aux*-1;
	       if(aux < r){ r=aux; resultado = res;}
	   } x++;
	 cout.precision(3);
	 cout<<fixed<<resultado<<"\n";
	}

}        
