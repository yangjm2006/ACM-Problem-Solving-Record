#include<bits/stdc++.h>
#define ll long long
#define MAXN 1010
using namespace std;

ll read(){
    char ch=getchar();
    ll s=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
} 

ll n, a, b;
ll s;

map<char, ll> ti;
bool vis1[50];
bool vis2[50];
ll sumpd[50];

struct node{
    ll t;
    char p;
    string v;
}pro[MAXN];

int main(){
    ll T = read();
    while(T--){
        n = read(), a = read(), b = read();
        s = read();
        ti.clear();
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(sumpd, 0, sizeof(sumpd));
        ll cnt = 0;

        ll sum = 0;

        ll sumac = 0;
        for(ll i = 1; i <= s; i++){
            cin >> pro[i].t >> pro[i].p >> pro[i].v;
        }

        vector<ll> vec;

        for(ll i = 1; i <= s; i++){
            ll t;
            char p;
            string v;
            t = pro[i].t, p = pro[i].p, v = pro[i].v;
            if(v == "rj"){
                ti[p]++;
            }else if(v == "ac" && vis1[p-'A'] == false){
                sumac += t + ti[p] * 20;
                sum++;
                vis1[p-'A'] = true;
            }else if(v == "pd" && vis2[p-'A'] == false && vis1[p-'A'] == false){
                cnt++;
                vec.push_back(t+ti[p]*20);
                vis2[p-'A'] = true;
            }
        }

        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            sumpd[i+1]=sumpd[i]+vec[i];
        }
        if(sum>a){
            printf("0\n");
        }else if(sum + cnt < a){
            printf("-1\n");
        }else{
            if(sumac + sumpd[a-sum] >= b){
                if(sum+cnt>=a+1){
                    printf("%lld\n", a-sum+1);
                }else{
                    printf("-1\n");
                }
            }else{
                printf("%lld\n", a-sum);
            }
        }
    }
    return 0;
}