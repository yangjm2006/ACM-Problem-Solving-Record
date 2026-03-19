#include<bits/stdc++.h>
#define ll int
#define MAXN 1000010
#define inf 10000000000
#pragma GCC optimize(3)
using namespace std;

ll n, m, A, B;
ll a[MAXN];
ll popct[2000];
ll sumj[2000];

void init(){
    for(ll k = 0; k < (1 << m); k++){
        for(ll i = 0; i <= 9; i++){
            if(k & (1 << i)){
                popct[k]++;
                sumj[k] += i+1;
            }
        }
    }
}

ll calc(ll i, ll k, ll st){
    ll s = a[i];
    s ^= k;
    if(st){
        s ^= (1 << m)-1;
    }
    return A * i * popct[s] + B * sumj[s];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // cin >> n >> m >> A >> B;

    n=1e5;m=10;A=100;B=500;

    init();

    for(ll i = 1; i <= n; i++){
        string s;
        // cin >> s;
        for(ll j = m; j >= 1; j--){
            a[i] *= 2;
            s[j-1]=rand()%2+'0';
            a[i] += (s[j-1] - '0');
        }
    }
    ll ans = -inf;

    for(ll k = 0; k < (1 << m); k++){
        ll las = 0;
        for(ll i = 1; i <= n; i++){
            las += max(calc(i, k, 0), calc(i, k, 1));
        }
        ans = max(ans, las);
    }

    cout << ans;

	return 0;
}