#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		if(a>b) cout<<"Win\n";
		else if(c>b) cout<<"WIN\n";
		else cout<<"nowin\n";
	}
	return 0;
}