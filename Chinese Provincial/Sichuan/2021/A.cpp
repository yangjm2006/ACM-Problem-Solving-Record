#include<bits/stdc++.h>
using namespace std;
int T,k,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>k;
		ans=0;
		for(int i=1;i<=6;i++) for(int j=i;j<=6;j++) if(i+j==k) ans++;
		cout<<ans<<'\n';
	} 
	return 0;
} 