#include<iostream>
#include<algorithm>
using namespace std;
const int N=200;
struct order{
	int a,b;
	bool operator < (const order& t){
		return a<t.a; 
	}
}o[N];
bool vis;
long long T,n,k,cnt,sum;
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++) cin>>o[j].a>>o[j].b;
		sort(o+1,o+n+1);
		cnt=0;sum=0;vis=1;
		for(int j=1;j<=n;j++){
			sum+=(o[j].a-cnt)*k-o[j].b;
			cnt=o[j].a;
			if(sum<0){
				vis=0;
				break;
			}
		}
		if(vis) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 