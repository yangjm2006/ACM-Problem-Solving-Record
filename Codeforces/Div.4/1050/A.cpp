#include<bits/stdc++.h>
using namespace std;
int T,x,n;
int main(){
	cin>>T;
	while(T--){
		cin>>x>>n;
		if(n&1) cout<<x<<'\n';
		else cout<<"0\n";
	}
	return 0;
}