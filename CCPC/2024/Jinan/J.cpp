#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int maxx(int a,int b,int c){
	int mx=0;
	mx=max(mx,a);mx=max(mx,b);mx=max(mx,c);
	return mx;
}
int T,n,x[N+100],y[N+100],z[N+100],numx[N+100],numy[N+100],numz[N+100],s[N+100];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c;
			x[i]=a;y[i]=b;z[i]=c;
			numx[a]=numy[b]=numz[c]=0;
			s[i]=0;
		}
		for(int i=1;i<=n;i++){
			numx[x[i]]++;numy[y[i]]++;numz[z[i]]++;
		}
		for(int i=1;i<=n;i++){
			s[maxx(numx[x[i]],numy[y[i]],numz[z[i]])+1]++;
		}
		for(int i=1;i<=n;i++){
			s[i]+=s[i-1];
			cout<<s[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}