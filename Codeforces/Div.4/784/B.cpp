#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[200010]={0};
		int ans=-1;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a[x]++;
			if(a[x]>=3){
				ans=x;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}