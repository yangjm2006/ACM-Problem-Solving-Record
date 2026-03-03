#include<bits/stdc++.h>
using namespace std;
int T,n,ans,num[10],to[400],vis;
bool cn[10];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	to['D']=1;to['C']=2;to['H']=3;to['S']=4;
	cin>>T;
	while(T--){
		for(int i=1;i<=4;i++) num[i]=0;
		vis=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c>>c;
			num[to[c]]++;
		}
		for(int i=1;i<=6;i++) cin>>cn[i];
		int res=0;
		for(int i=1;i<=4;i++){
			ans+=num[i]/5;
			num[i]%=5;
			res+=num[i];
		}
		if(cn[5]) vis++;
		if(cn[6]) vis++;
		for(int i=1;i<=4;i++) if(cn[i]&&num[i]+3>=5&&res>=5){
			ans++;
			res-=5;
			num[i]=cn[i]=0;
		}
		for(int i=1;i<=4;i++) if(vis>=1&&num[i]==4&&res>=5){
			vis--;
			ans++;
			res-=5;
			num[i]=0;
		}
		for(int i=1;i<=4;i++) if(vis>=1&&cn[i]&&num[i]==1&&res>=5){
			vis--;
			ans++;
			res-=5;
			num[i]=cn[i]=0;
		}
		for(int i=1;i<=4;i++) if(vis>=2&&num[i]==3&&res>=5){
			vis-=2;
			ans++;
			res-=5;
			num[i]=0;
		}
		for(int i=1;i<=4;i++) if(vis>=2&&cn[i]&&num[i]==0&&res>=5){
			vis-=2;
			ans++;
			res-=5;
			num[i]=cn[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}