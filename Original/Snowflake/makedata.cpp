#include<bits/stdc++.h>
using namespace std;
const int mod=1000000000;
const int N=200;
int n=1e5-109,m=98,a[N],b[N],c[N],p[N];
map<int,int> mp;
int randm(){
	return rand()%12;
}
int rd(){
	if(rand()%10) return rand()%10+1;
	return (rand()*rand()+rand())%mod+10;
}
void op1(int x){
	for(int i=0;i<m;i++) b[(i+x)%m]=a[i];
	for(int i=0;i<m;i++) a[i]=b[i];
}
void op2(){
	for(int i=0;i<m/2;i++) swap(a[i],a[m-1-i]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("snowflake5.in","w",stdout);
	srand(time(NULL));
	for(int i=0;i<=m*100;i++) mp[i]=rd();
	cout<<n<<" "<<m<<'\n';
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<mp[randm()]<<" ";
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=m;i++) a[i-1]=mp[randm()];
	for(int i=1;i<=n;i++){
		if(i<n/3-10){
			if(rand()%4==0){
				for(int i=0;i<m;i++) for(int j=0;j<m;j++)
				if(rand()%3) swap(a[i],a[j]);
			}else if(rand()%2){
				op1(rand());
			}else op2();
		}else{
			if(rand()%10==0){
				for(int i=0;i<m;i++) for(int j=0;j<m;j++)
				if(rand()%3) swap(a[i],a[j]);
			}else if(rand()%2){
				op1(rand());
			}else op2();
			if(i==n/3){
				for(int i=0;i<m;i++) a[i]=101;
				a[1]=a[2]=a[5]=100;
			}
			if(i==(n/3)*2){
				for(int i=0;i<m;i++) a[i]=101;
				a[1]=a[4]=a[5]=100;
			}
		}
		for(int i=0;i<m;i++) cout<<a[i]<<" ";
		cout<<'\n';
	}
	cout<<'\n';
	return 0;
}
