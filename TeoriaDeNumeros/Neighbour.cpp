#include <bits/stdc++.h>
using namespace std;
	
string numero;
string n="1000000";

int main()
{
	cin>>numero;
	if (next_permutation(numero.begin(),numero.end()))
	{
		cout<<numero<<"\n";
	}
	else{
		cout<<"0\n";
	}
	return 0;
}

