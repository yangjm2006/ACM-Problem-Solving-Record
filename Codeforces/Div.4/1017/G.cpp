#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,m,len,ans,vis,sum;
deque<ll> q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        q.clear();
        ans=vis=len=0;
        cin>>m;
        for(int i=1,id;i<=m;i++){
            cin>>id;
            if(id==1){
                if(vis%2==0){
                    if(!q.empty()){
                        ans+=sum-len*q.back();
                        q.push_front(q.back());
                        q.pop_back();
                    }
                }else{ 
                    if(!q.empty()){
                        ans+=sum-len*q.front();
                        q.push_back(q.front());
                        q.pop_front();
                    }
                }
            }else if(id==2){
                ans=(len+1)*sum-ans;
                vis++;
            }else{
                ll x;
                cin>>x;
                sum+=x;
                if(vis%2==0){
                    q.push_back(x);
                }else{
                    q.push_front(x);
                }
                len++;
                ans+=x*len;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}