#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
ll T,n,a[N],ans;
void check(int x){
	ll res=1ll<<x;
	ll be=0,ed=0,len=0,nw=0,cnt=0;
	bool cn=1,nt=1;
	for(int i=1;i<=n;i++){
		if((res&a[i])==0){
			nw++;
			nt=0;
		}
		else{
			nw=0;
			cn=0;
		}
		len=max(len,nw);
	}
	for(int i=1;i<=n;i++) if((res&a[i])!=0){
		be=i-1;
		break;
	}
	for(int i=n;i>=1;i--) if((res&a[i])!=0){
		ed=n-i;
		break;
	}
	len=max(len,be+ed);
	for(int i=1;i<=n;i++) if(i*(i+1)/2>=len){
		cnt=i;
		break;
	}
//	cout<<x<<" "<<cn<<" "<<cnt<<"---------\n";
	if(cn||nt) ;
	else ans=max(ans,cnt);
	return; 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<=32;i++) check(i);
		cout<<ans<<'\n';
	}
	return 0;
}