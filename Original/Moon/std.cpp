#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(n==2*k) cout<<"2\n";
		else cout<<"1\n";
	}
	return 0;
}
