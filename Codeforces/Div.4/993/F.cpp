#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll n,m,q,s,a[N],b[N],x;
bool s1[N*2+100],s2[N*2+100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        // s1.insert(s-a[i]);
        if(s-a[i]<N&&s-a[i]>-N) s1[s-a[i]+N]=1;
    }
    s=0;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        s+=b[i];
    }
    for(int i=1;i<=m;i++){
        // s2.insert(s-b[i]);
        if(s-b[i]<N&&s-b[i]>-N) s2[s-b[i]+N]=1;
    }
    // cout<<"\n";
    while(q--){
        cin>>x;
        bool f=0;
        for(ll i=1;i*i<=abs(x);i++){
            if(x%i==0){
                // if((s1.find(i)!=s1.end()&&s2.find(x/i)!=s2.end())||(s1.find(x/i)!=s1.end()&&s2.find(i)!=s2.end())){
                //     f=1;
                //     break;
                // }
                if((s1[i+N]&&s2[x/i+N])||(s1[x/i+N]&&s2[i+N])){
                    f=1;
                    break;
                }
                // if((s1.find(-i)!=s1.end()&&s2.find(-x/i)!=s2.end())||(s1.find(-x/i)!=s1.end()&&s2.find(-i)!=s2.end())){
                //     f=1;
                //     break;
                // }
                if((s1[-i+N]&&s2[-x/i+N])||(s1[-x/i+N]&&s2[-i+N])){
                    f=1;
                    break;
                }
            }
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}