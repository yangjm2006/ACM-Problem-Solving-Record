#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
const ll MOD = 998244353;
using namespace std;

ll n;
ll ans = 0;
ll st[MAXN << 2], tot = 0;

void repe(){
	ll temp = tot;
	for(ll i = 1; i <= temp; i++){
		st[++tot] = st[i];
	}
}

int main(){
	cin >> n;
	string s;
	for(ll i = 1; i <= n; i++){
		cin >> s;
		if(s == "Push"){
			ll x;
			cin >> x;
			st[++tot] = x;
			ans += x;
			ans %= MOD;
		}else if(s == "Repeat"){
			if(tot < 200000){
				repe();
			}
			ans *= 2;
			ans %= MOD;
		}else{
			ans -= st[tot];
			ans += MOD;
			ans %= MOD;
			tot--;
		}
		ans = ans % MOD;
		printf("%lld\n", ans);
	}
	
	return 0;
}