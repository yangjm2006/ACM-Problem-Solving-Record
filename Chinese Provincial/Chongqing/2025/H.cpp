#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
ll T;
ll n;
ll a[MAXN], b[MAXN], c[MAXN];
map <ll, ll> m;
int main(){
	cin>>T;
	while(T--){
		cin >> n;
		m.clear();
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(ll i = 1; i <= n; i++){
			cin >> b[i];
			m[b[i]] = i;
		}
		for(ll i = 1; i <= n; i++){
			cin >> c[i];
		}
		
		bool f = true;
		ll las = 0;
		
		for(ll i = 1; i <= n; i++){
			if(c[i] == 0){
				continue;
			}
			if(m[a[i]] <= las){
				f = false;
				break;
			}
			las = m[a[i]];
		}
		
		if(f){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}