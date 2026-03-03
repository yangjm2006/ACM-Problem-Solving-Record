#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll base=277;
ll a[200000],n,m,k,v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ll h=0;
			for(int o=1;o<=k;o++){
				char c;
				cin>>c; 
				h=h*base+c;
			}
			a[(i-1)*m+j]=h;
		}
	}
	if(a[1]==a[2]) v=a[1];
	else if(a[2]==a[3]) v=a[2];
	else v=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]!=v) cout<<(i-1)/m+1<<" "<<(i-1)%m+1;
	}
	return 0;
}