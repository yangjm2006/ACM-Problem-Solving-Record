#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MOD 1000000007
using namespace std;
ll n, k;
ll fa[MAXN];
ll si[MAXN];
ll d[MAXN];

ll findd(ll x){
    return fa[x] == x ? fa[x] : fa[x] = findd(fa[x]);
}

void merge(ll fu, ll fv){
    if(si[fu] > si[fv]){
        fa[fv] = fu;
        si[fu] += si[fv];
    }else{
        fa[fu] = fv;
        si[fv] += si[fu];
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        fa[i] = i;
        si[i] = 1;
    }

    ll u, v;
    ll ans = 1;
    ll tot = n;
    ll cnt = 0;
    bool is = false;

    for(ll i = 1; i <= k; i++){
        
        cin >> u >> v;
        d[u]++, d[v]++;
        ll fu, fv;
        fu = findd(u), fv = findd(v);
        if(fu == fv){
            is = true;
        }else{
            merge(fu, fv);
            tot--;
        }
    }
    for(ll i = 1; i <= n; i++){
        if(d[i] > 2){
            cout << "-1";
            return 0;
        }
    }

    if(is){
        cout << "-1";
    }else{
        set<ll> st;
        for(ll i = 1; i <= n; i++){
            st.insert(findd(i));
        }
        ll ans = 1;
        for(auto v : st){
            if(si[v] > 1){
                ans *= 2;
                ans %= MOD;
            }
        }

        for(ll i = 1; i <= tot; i++){
            ans *= i;
            ans %= MOD;
        }
        cout << ans;
    }

    return 0;
}