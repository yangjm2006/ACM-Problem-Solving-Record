#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b){
	if(a==0||a==b) return 1;
	while(b%2==0) b/=2;
	return a%b==0;
}
int a,b,cnt;
void work(int x,int y){
	if((x==0||x==a)&&(y==0||y==b)){
		cout<<cnt<<'\n';
		return;
	}
	cnt++;
	int u,v,nx,ny;
	if(x<=a/2){
		u=0;
		nx=x*2;
	}else{
		u=a;
		nx=2*x-a;
	}
	if(y<=b/2){
		v=0;
		ny=y*2;
	}else{
		v=b;
		ny=2*y-b;
	}
	work(nx,ny);
	cout<<nx<<" "<<ny<<" "<<u<<" "<<v<<'\n';
}
int x,y;
int main(){
	cin>>a>>b>>x>>y;
	if(!(check(x,a)&&check(y,b))) cout<<"-1"; 
	else work(x,y);
	return 0;
}