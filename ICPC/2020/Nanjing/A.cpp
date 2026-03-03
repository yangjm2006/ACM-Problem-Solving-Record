#include<bits/stdc++.h>
using namespace std;
bool mp[30][30];
int main(){
	cout<<"20 20\n";
	for(int i=1;i<=20;i+=2){
		for(int j=1;j<=20;j++) mp[i][j]=1;
	}
	for(int i=2;i<=20;i+=4) mp[i][1]=1;
	for(int i=4;i<=20;i+=4) mp[i][20]=1;
	for(int i=2;i<=20;i+=2) mp[20][i]=1;
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++) cout<<mp[i][j];
		cout<<'\n';
	}
	return 0;
} 