#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll T,x,y,tmp;
vector<int> v1,v2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		v1.clear();v2.clear();
		cin>>x>>y;
        tmp=x;
		while(x||y){
			v1.push_back(x%4);x/=4;
			v2.push_back(y%4);y/=4;
		}
        x=tmp;
		if(v1.size()==v2.size()){
			for(int i=v1.size()-1;i>=0;i--){
				if(v1[i]==v2[i]) x-=v1[i]*(1ll<<(i*2));
				else{
					if(v1[i]==2) x-=v1[i]*(1ll<<(i*2));
					break;
				}
			}
			cout<<x<<'\n';
		}else cout<<x<<'\n';
	}
	return 0;
}