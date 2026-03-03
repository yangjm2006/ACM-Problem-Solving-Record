#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int T,n,a[N][N],cnt[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cnt[i]=0;
		if(n>=4){
			int res=1;
			cnt[res]=1;
			for(int i=1;i<n;i+=2){
				for(int j=1;j<=n;j++){
					cnt[res]++;
					a[i][j]=res;
					a[i+1][j]=cnt[res];
					if(cnt[res]==n){
						res++;
						cnt[res]=res;
					}
				}
			}
			if(n%2){
				for(int i=1;i<=n;i+=2){
					cnt[res]++;
					a[n][i]=res;
					a[n][i+1]=cnt[res];
					if(cnt[res]==n){
						res++;
						cnt[res]=res;
					}
				}
				a[n][n]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) cout<<min(n,a[i][j])<<" ";
				cout<<'\n';
			}
		}else if(n==1) cout<<"1\n";
		else if(n==2){
			cout<<"1 1\n2 2\n";
		}else cout<<"1 2 3\n1 2 3\n3 3 3\n";
	}
	return 0;
}