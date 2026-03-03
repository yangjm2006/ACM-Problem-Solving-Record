#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,n,k,m,a[N],res[N],tmp[N],mp[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>m;
		for(int i=0;i<=k;i++) mp[i]=0;
		for(int i=0;i<n;i++) res[i]=tmp[i]=0;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			if(mp[a[i]]){
				res[i]++;
				mp[a[i]]--;
			}else mp[a[i]]++;
		}
		for(int i=0;i<n;i++){
			if(mp[a[i]]){
				res[i]++;
				mp[a[i]]--;
			}else mp[a[i]]++;
		}
		for(int i=0;i<=k;i++) mp[i]=0;
		for(int i=0;i<m%(2*n);i++){
			if(mp[a[i%n]]){
				tmp[i%n]++;
				mp[a[i%n]]--;
			}else mp[a[i%n]]++;
		}
		ll cnt=m/(2*n);
		for(int i=0;i<n;i++){
			cout<<res[i]*cnt+tmp[i]<<(i==n-1?"":" ");
		}
		cout<<'\n';
	}
	return 0;
} 