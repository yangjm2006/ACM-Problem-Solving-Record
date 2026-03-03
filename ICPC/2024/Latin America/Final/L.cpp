#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
bool cn1[N],cn2[N];
int n,m1,m2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m1;j++){
			char c;
			cin>>c;
			if(c=='-') cn1[i]=1;
		}
		for(int j=1;j<=m2;j++){
			char c;
			cin>>c;
			if(c=='*') cn2[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(cn1[i]==1&&cn2[i]==1){
			cout<<"N";
			return 0;
		}
	}
	cout<<"Y";
	return 0;
}