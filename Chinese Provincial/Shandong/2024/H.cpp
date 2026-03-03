#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct node{
    int x,y;
}p[N];
int T,n;
map<int,int> tox,toy,invx,invy;
bool vis[300][300];
set<int> sx,sy;
int main(){
    cin>>T;
    while(T--){
        sx.clear();sy.clear();tox.clear();toy.clear();invx.clear();invy.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
            sx.insert(p[i].x);sy.insert(p[i].y);
        }
        int cntx=0,cnty=0;
        for(int i:sx){
            tox[i]=++cntx;
            invx[cntx]=i;
        }
        for(int i:sy){
            toy[i]=++cnty;
            invy[cnty]=i;
        }
        for(int i=1;i<=n;i++){
            p[i].x=tox[p[i].x];
            p[i].y=toy[p[i].y];
            vis[p[i].x][p[i].y]=1;
        }
        for(int i=1;i<=cntx;i++){
            for(int j=1;j<=cnty;j++){
                
            }
        }
    }
    return 0;
}