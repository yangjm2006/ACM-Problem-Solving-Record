#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+500;
ll T,n,m,l[N],r[N],c[N],minn,ad[N];
set<int> st;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		minn=1e18;
		cin>>n>>m;
		mp.clear();st.clear();
		for(int i=0;i<=2*m+100;i++) ad[i]=0;
		for(int i=1;i<=m;i++){
			cin>>l[i]>>r[i]>>c[i];
			st.insert(l[i]);
			st.insert(r[i]);
		}
		st.insert(1);
		st.insert(n);
		int res=0;
		for(set<int>::iterator it=st.begin();it!=st.end();it++){
			mp[*it]=++res;
		}
		for(int i=1;i<=m;i++){
			ad[mp[l[i]]]+=c[i];
			ad[mp[r[i]]]-=c[i];
		}
		for(int i=1;i<=res;i++) ad[i]+=ad[i-1];
		for(int i=1;i<=res-1;i++) minn=min(minn,ad[i]);
		cout<<minn<<'\n';
	}
	return 0;
}