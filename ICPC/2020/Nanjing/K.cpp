#include<bits/stdc++.h>
using namespace std;
int n,k,a[2000000];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=i;
	if(k==0){
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<=(k-1)/2;i++){
		swap(a[i*2],a[i*2+1]);
	}
	if(k%2==0) swap(a[1],a[n]);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
} 