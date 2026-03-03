#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll T,n,q,a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>q;
		for(int i=0;i<n;i++) a[i]=0;
		for(int i=0;i<q;i++){
			ll k,x;
			cin>>k>>x;
			a[0]+=k/n;
			k%=n;
			if(k){
				a[x]++;
				if(x+k>n){
					a[0]++;
					a[(x+k)%n]--; 
				}
				else a[x+k]--;
			}
		}
		for(int i=0;i<n;i++){
			if(i) a[i]+=a[i-1];
			cout<<a[i]<<" ";
		}
		cout<<'\n';
	}
	return 0;
} 