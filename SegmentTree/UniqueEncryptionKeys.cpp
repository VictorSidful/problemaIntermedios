#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[100002];
int ST[200002];

int helper(int val){
	if(val > 0){
		return 1;
	}else if(val == 0){
		return 0;
	}else{
		return -1;
	}
}
void imprimirST(){
	for(int i=1;i<=n*2;i++){
		cout<<ST[i]<<" ";
	}cout<<"\n";
}

void inicializarST(int nodo,int ini,int fin){
	if (ini == fin)
	{
		ST[nodo] = helper(arr[ini]);
	}else{
		int mitad = (ini + fin)/2;
		inicializarST(nodo*2,ini,mitad);
		inicializarST(nodo*2+1,mitad+1,fin);
		ST[nodo]= ST[nodo*2]*ST[nodo*2+1];
	}
}

void update(int nodo,int ini,int fin,int x,int val){
	if(ini == fin && ini == x){
		ST[nodo] = helper(val);
	}else if (ini <= x && x <= fin){
		int mitad = (ini + fin)/2;
		update(nodo*2, ini,mitad,x,helper(val));
		update(nodo*2+1,mitad+1,fin,x,helper(val));
		ST[nodo] = ST[nodo*2]*ST[nodo*2+1];
	}
}

int query(int nodo,int ini,int fin,int l,int r){
	
	if(fin < l || r < ini){
		return 1;
	}else if(l <= ini && fin <= r){
		return ST[nodo];
	}else{
		int mitad = (ini + fin)/2;
		int izq = query(nodo*2,ini,mitad,l,r);
		int der = query(nodo*2+1, mitad +1,fin,l,r);
		return (izq*der);
	}
}

int main(){

	while(cin>>n>>k){
		
		for (int i = 1; i <= n; i++)
			cin>>arr[i];
			
		inicializarST(1,1,n);
		
		for(int i=1; i<=k; i++){
			
			char opcion;		
			cin>>opcion;
			
			if(opcion == 'C'){
				
			//	cout<<"i: "<<i<<" Opcion ("<<opcion<<")  ";
				int x,val;
				cin>>x>>val;
			//	cout<<"x: "<<x<<" val: "<<val<<"\n";
				update(1,1,n,x,helper(val));
			//	imprimirST();
				
			}else{
			//	cout<<"else - i: "<<i<<" Opcion ("<<opcion<<"   ";
				int l,r;
				cin>>l>>r;
			//	cout<<"l: "<<l<<" r : "<<r<<"\n";
				
				int res = query(1,1,n,l,r);
				
				if(res == 0){
					printf("0");
				}else if(res <0){
					printf("-");
				}else{
					printf("+");
				}
			}
		}
		
		printf("\n");	
	}	

	return 0;
}
