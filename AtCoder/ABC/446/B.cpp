#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[200];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        bool f=0;
        for(int j=1;j<=l;j++){
            int x;
            cin>>x;
            if(f==0&&vis[x]==0){
                cout<<x<<'\n';
                vis[x]=1;
                f=1;
            }
        }
        if(!f) cout<<"0\n";
    }
    return 0;
}