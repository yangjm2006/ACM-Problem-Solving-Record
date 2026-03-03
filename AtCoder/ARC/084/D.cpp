#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int INF=1e9;
struct edge{
    int v,w,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int w){
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
int dis[N],k;
void bfs(){
    for(int i=0;i<k;i++) dis[i]=INF;
    deque<int> q;
    q.push_back(1);
    dis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(w==1){
                    q.push_back(v);
                }else{
                    q.push_front(v);
                }
            }
        }
    }
}
int main(){
    cin>>k;
    for(int i=1;i<k;i++){
        adde(i,(i+1)%k,1);
    }
    for(int i=1;i<k;i++){
        adde(i,i*10%k,0);
    }
    bfs();
    cout<<dis[0];
    return 0;
}