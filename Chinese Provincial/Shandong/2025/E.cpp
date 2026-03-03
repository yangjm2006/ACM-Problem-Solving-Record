#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,n,k,a[N],sum,maxx,num[N],s[N];
bool check(ll x){
	if(x>=maxx){
		if((n*x-sum)<=k){
			cout<<x<<'\n';
			return 1;
		}
		return 0;
	}
	ll res=0;
	for(ll i=1;i<=maxx;i+=x){
		if(i+x-1<=maxx) res+=(num[i+x-1]-num[i-1])*(i+x-1)-(s[i+x-1]-s[i-1]);
		else res+=(num[maxx]-num[i-1])*(i+x-1)-(s[maxx]-s[i-1]);
		if(res>k) return 0;
	}
//	if((k-res)%x!=0) return 0;
	cout<<x<<'\n';
	return 1;
}
vector<ll> v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		v.clear();
		cin>>n>>k;
		sum=maxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		for(int i=0;i<=maxx;i++) num[i]=s[i]=0;
		for(int i=1;i<=n;i++){
			num[a[i]]++;
			s[a[i]]+=a[i];
		}
		for(int i=1;i<=maxx;i++){
			num[i]+=num[i-1];
			s[i]+=s[i-1];
		}
		bool cn=0;
		for(ll i=1;i*i<=sum+k;i++) if((sum+k)%i==0){
			v.push_back(i);
			if(check((sum+k)/i)){
				cn=1;
				break;
			}
		}
		if(!cn) for(int i=v.size()-1;i>=0;i--){
			if(check(v[i])) break;
		}
	}
	return 0;
} 