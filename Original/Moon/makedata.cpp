#include<bits/stdc++.h>
using namespace std;
const int mod=4e8;
int T=4e4,n,k;
int main(){
	freopen("moon2.in","w",stdout);
	srand(time(NULL));
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cout<<T<<'\n';
	while(T--){
		n=rand()*rand()%mod+100;
		if(rand()%10) cout<<n<<" "<<min(n,max(1,n/3*2-rand()%(n/3)))<<'\n';
		else cout<<n<<" "<<n/2<<'\n';
	}
	return 0;
}
