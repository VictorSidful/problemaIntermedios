#include <bits/stdc++.h>
using namespace std;
vector <int> marbles;
int binary(int x){
 	int ini=0,fin=marbles.size()-1,res=-1,mit;
	while(ini <= fin){
	   mit= 0.5*(ini+fin);
	   if(marbles[mit] == x){
	   	res=mit;
		fin=mit-1;
	   }
	   if(marbles[mit]>x) fin=mit-1;
	   if(marbles[mit]<x) ini=mit+1;
	}
	return res;
}
int main(){
	int N,Q;
	int numCase=1;
	while(cin>>N>>Q){
	if(!N && !Q) break;
        int num;
	marbles = vector<int> (N);
		for(int i=0;i<N;i++){
		   cin>>num;
		   marbles[i]=num;	
		}
	/*	cout<<"Marbles: \n";
		for(int i=0;i<N;i++){  
		   cout<<marbles[i]<<",";	
		}cout<<"\n";  */
		sort(marbles.begin(),marbles.end());
		
	/*	cout<<"Marbles Ordenadas: \n";
		for(int i=0;i<N;i++){   
		   cout<<marbles[i]<<",";	
		}cout<<"\n";    */
		cout<<"CASE# "<<numCase<<":\n";numCase++;
		int querie;
		for(int j=0; j < Q; j++){
		   cin>>querie;
			int res = binary(querie);
			if(res == -1) cout<<querie<<" not found\n";
			else cout<<querie<<" found at "<<res+1<<"\n";		
		}
	}
 return 0;
}
