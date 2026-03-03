#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,b[10],d[10],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>b[1]>>b[2]>>b[0];
		cin>>d[1]>>d[2]>>d[0];
		for(int i=0;i<=2;i++){
			int j=(i+2)%3;
			ll w=min(d[i],b[j]);
			ans+=w;
			b[j]-=w;
			d[i]-=w;
		}
		for(int i=0;i<=2;i++){
			ll w=min(d[i],b[i]);
			b[i]-=w;
			d[i]-=w;
		}
		for(int i=0;i<=2;i++){
			int j=(i+1)%3;
			ans-=min(d[i],b[j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 