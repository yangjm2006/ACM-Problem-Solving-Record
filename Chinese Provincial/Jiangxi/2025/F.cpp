#include<bits/stdc++.h>
#define ll long long
#define db double
#define MAXN 100010
using namespace std;

db r[MAXN], c[MAXN];

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll n, k;
        db r0, c0, L, R;
        db p;
        cin >> n >> k;
        scanf("%lf%lf%lf%lf%lf", &r[0], &c[0], &p, &L, &R);

        for(ll i = 1; i <= n; i++)r[i] = L;

        for(ll i = 1; i <= k; i++){
            ll pos;
            scanf("%lld", &pos);
            scanf("%lf", &r[pos]);
        }

        db ans = 0;
        
        for(ll i = 1; i <= n; i++){
            c[i] = p * c[i-1] + (1-p) * r[i-1];
            ans += c[i]-r[i];
        }

        printf("%.10lf\n", ans);
    }
    return 0;
}