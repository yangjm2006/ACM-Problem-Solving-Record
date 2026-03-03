#include<bits/stdc++.h>
using namespace std;
const int N=20000;
int T,n,q;
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>q;
        bool f=1;
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            if(c=='A') vis[i]=1;
            else vis[i]=0;
            f&=vis[i];
        }
        while(q--){
            int x;
            cin>>x;
            if(f){
                cout<<x<<'\n';
                continue;
            }
            int cnt=0;
            while(x){
                cnt++;
                if(vis[(cnt-1)%n+1]) x--;
                else x/=2;
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}