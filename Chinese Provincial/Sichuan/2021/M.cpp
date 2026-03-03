#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll n,k,x,s[N],t[N],p[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>x>>p[0];
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=k;i++) cin>>t[i];
	for(int i=1;i<=k;i++) cin>>p[i];
	sort(s+1,s+1+n,greater<ll>());
	int it=0;
	for(int i=1;i<=n;i++){
		while(s[i]*(p[it]-t[it])<x&&it<=k){
			it++;
		}
		if(it==k+1){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 