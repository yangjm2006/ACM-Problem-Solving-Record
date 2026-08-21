#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,n,m,ans,len;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		mp.clear();ans=len=0;
		cin>>n>>m;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			mp[x]++;
		}
		for(int i=1,x;i<=m;i++){
			cin>>x;
			mp[x]=0;
		}
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			if(it->second==0) len=0;
			else len+=it->second;
			ans=max(ans,len);
		}
		if(!ans) cout<<"Impossible\n";
		else cout<<ans<<'\n';
	}
	return 0;
} 