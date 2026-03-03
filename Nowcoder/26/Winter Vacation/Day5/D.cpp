#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
struct node{
    ll c,w;
    bool operator < (const node &_) const{
        return w>_.w;
    }
};
priority_queue<node> q;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll c,w;
        cin>>c>>w;
        q.push((node){c,w});
    }
    ll ans=0;
    while(!(q.size()==1&&q.top().c==1)){
        ll c=q.top().c,w=q.top().w;q.pop();
        if(c%2==0){
            (ans+=c*w)%=mod;
            q.push((node){c/2,w*2});
        }else{
            (ans+=c*w)%=mod;
            if(c/2) q.push((node){c/2,w*2});
            q.push((node){1,w+q.top().w});
            // q.top().c--;
            // if(q.top().c==0) q.pop();
            ll c2=q.top().c,w2=q.top().w;
            q.pop();
            (ans+=w2)%=mod;
            c2--;
            if(c2){
                q.push((node){c2,w2});
            }
        }
    }
    cout<<ans;
    return 0;
}