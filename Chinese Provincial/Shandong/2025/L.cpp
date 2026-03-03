#include<bits/stdc++.h>
using namespace std;
int mp[300];
char a,b;
int T,x,y;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mp['O']=0;
	mp['B']=10;
	mp['A']=20;
	mp['F']=30;
	mp['G']=40;
	mp['K']=50;
	mp['M']=60;
	cin>>T;
	while(T--){
		cin>>a>>x>>b>>y;
		if(mp[a]+x<mp[b]+y) cout<<"hotter\n";
		else if(mp[a]+x==mp[b]+y) cout<<"same\n";
		else cout<<"cooler\n";
	}
	return 0;
}