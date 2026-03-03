#include<bits/stdc++.h>
using namespace std;
long long t,n,q;
long long a[100100],ww[100100],qz[100100],ans,mp[100100],mx=INT_MIN,sl[100100];
long long u[100100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	// freopen("mexdnc2.in","r",stdin);
	// freopen("mexdnc3.out","w",stdout);
	cin>>t;
	while(t--){
		mx=INT_MIN;
		ans=0;
		cin>>n>>q;
		long long a,b;
		map<long long,long long>mp;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			if(a<=n){
				mx=max(mx,a);
				mp[a]+=b;
			}
            else{
                ans=1;
            }
		}
		long long qz1=INT_MAX;
		long long jl=0;
		for(int i=0;i<=mx;i++){
			if(mp[i]!=0){
				u[i]=min(mp[i],qz1);
			}
            else{
                break;
                ans=1;
            }
			qz1=min(u[i],qz1);
            jl=i;
		}
		qz1=0;
		for(int i=mx;i>=0;i--){
			qz[mx-i]+=qz[mx-i-1]+(i+1)*(u[i]-qz1);
			qz1=max(qz1,u[i]);
		}
		int m=0;
		for(int i=1;i<=q;i++){
			cin>>m;
			if(m==0){
				if(mp[0]!=0){
					cout<<"-1\n";
				}
				else{
					cout<<"1\n";
				}
			}
			else{
				if(qz[mx]<m){
					cout<<"-1\n";
				}
				else{
					if(jl>m)cout<<"2\n";
					else{
						int w=lower_bound(qz,qz+mx+1,m)-qz;
					cout<<u[mx-w+1]+(m-qz[w-1])/(mx-w+1)+((m-qz[w-1])%(mx-w+1)!=0)<<"\n";
					}
					
				}
			}
		}
		for(int i=0;i<=mx;i++){
			qz[i]=mp[i]=u[i]=0;
		}
	}
	return 0;
}