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
		int k=0,it1=0,it2=1,t1,t2;
		while(k<m&&it1<m&&it2<m){
			if(a[(it1+k)%m]==a[(it2+k)%m]) k++;
			else{
				if(a[(it1+k)%m]>a[(it2+k)%m]) it1+=k+1;
				else it2+=k+1;
				if(it1==it2) it2++;
				k=0;
			}
		}
		t1=min(it1,it2);
		k=0,it1=m-1,it2=m-2;
		while(k<m&&it1>=0&&it2>=0){
			if(a[(it1-k+m)%m]==a[(it2-k+m)%m]) k++;
			else{
				if(a[(it1-k+m)%m]>a[(it2-k+m)%m]) it1-=k+1;
				else it2-=k+1;
				if(it1==it2) it1--;
				k=0;
			}
		}
		t2=max(it1,it2);
		bool cn=0;
		for(int i=0;i<m;i++)
			if(a[(t1+i)%m]<a[(t2-i+m)%m]){
				cn=1;
				break;
			}else if(a[(t1+i)%m]>a[(t2-i+m)%m]) break;
		ull h1=0,h2=0;
		if(cn){
			for(int i=0;i<m;i++){
				h1=(h1*base1+a[(t1+i)%m])%mod;
				h2=h2*base2+a[(t1+i)%m];
			}
		}
		else{
			for(int i=0;i<m;i++){
				h1=(h1*base1+a[(t2-i+m)%m])%mod;
				h2=h2*base2+a[(t2-i+m)%m];
			}
		}
		if(!mp[make_pair(h1,h2)]){
			ans++;
			mp[make_pair(h1,h2)]=1;
		}
	}
	cout<<ans;
	return 0;
}
