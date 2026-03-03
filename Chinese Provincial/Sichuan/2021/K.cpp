#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,k,ans[N];
bool cmp(int x,int y){
	if(x%k==y%k) return x<y;
	else return x%k<y%k;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) ans[i]=i;
	sort(ans+1,ans+1+n,cmp);
	for(int i=1;i<=n-1;i++) cout<<ans[i]<<" ";
	cout<<ans[n];
	return 0;
} 