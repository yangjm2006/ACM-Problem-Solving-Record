#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=200;
const ull mod=1e9+7,base1=233,base2=373;
ull n,m,a[N],ans;
map<pair<ull,ull>,bool> mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int _=1;_<=n;_++){
		for(int i=0;i<m;i++) cin>>a[i];
		bool cn=0;
		for(int i=0;i<m;i++){
			ull h1=0,h2=0;
			for(int j=0;j<m;j++){
				h1=(h1*base1+a[(i+j)%m])%mod;
				h2=h2*base2+a[(i+j)%m];
			}
			if(!mp[make_pair(h1,h2)]){
				if(!cn) ans++,cn=1;
				mp[make_pair(h1,h2)]=1;
			}else break;
		}
		for(int i=0;i<m/2;i++) swap(a[i],a[m-1-i]);	
		for(int i=0;i<m;i++){
			ull h1=0,h2=0;
			for(int j=0;j<m;j++){
				h1=(h1*base1+a[(i+j)%m])%mod;
				h2=h2*base2+a[(i+j)%m];
			}
			if(!mp[make_pair(h1,h2)]){
				if(!cn) ans++,cn=1;
				mp[make_pair(h1,h2)]=1;
			}else break;
		}
	}
	cout<<ans;
	return 0;
}
