#include <bits/stdc++.h>
using namespace std;

vector <int> pilas;
int binaria(int x){
 int res=0,mid,ini=0,fin=pilas.size()-1;
	while(ini<=fin){
	 mid= 0.5*(ini+fin);
	 if(pilas[mid] == x){ res=mid; fin=mid-1;}
	 if(pilas[mid] < x) ini=mid+1;
	 if(pilas[mid] > x){ res=mid; fin=mid-1;}
	}
	return res;
}
int main(){
   int N;cin>>N;
    pilas= vector<int> (N+1);
	int num,sum=0;
	for(int i=0;i<N;i++){
	   cin>>num; sum+=num;
	   pilas[i]=sum;}
	//for(int i=0;i<N;i++){
	 // cout<<i<<" "<<pilas[i];} cout<<"\n";
     int Q; cin>>Q;
	for(int j=0;j<Q;j++){
	 int querie; cin>>querie;
	 int res= binaria(querie);
	 cout<<res+1<<"\n";
	}	
	
 return 0;
}