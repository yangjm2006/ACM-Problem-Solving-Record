#include<bits/stdc++.h>
using namespace std;
bool vis[200][6];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=3*n-3;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(v==2){
            if(vis[u][1]||vis[u][3]){
                if(i&1) cout<<"Nocriz";
                else cout<<"Sheauhaw";
                return;
            }
        }else{
            if(vis[u][2]){
                if(i&1) cout<<"Nocriz";
                else cout<<"Sheauhaw";
                return;
            }
        }
        vis[u][v]=1;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
	return 0;
} 