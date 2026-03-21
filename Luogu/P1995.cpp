#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
const double INF=1e18;
struct Point{
    ll x,y;int id;
}a[N],b[N];
typedef Point Vector;
double operator ^ (Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}
Point operator - (Point a,Point b){
    return (Point){a.x-b.x,a.y-b.y};
}
bool operator != (Point a,Point b){
    return (a.x!=b.x)||(a.y!=b.y)||(a.id!=b.id);
}
struct Line{
    ll x,y1,y2;int id1,id2;
}l[N];
struct edge{
    int v;
    double w;
};
int n;
double dis[N];
int s,t;
bool vis[N];
vector<edge> e[N];
double spfa(){
    for(int i=1;i<=t;i++) dis[i]=INF;
    queue<int> q;q.push(s);dis[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(auto x:e[u]){
            int v=x.v;double w=x.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    // for(int i=1;i<=t;i++) cout<<dis[i]<<" ";cout<<"!!!!!\n";
    return dis[t];
}
int cnt;
vector<Line> vec;
double distance(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void make(Point p){
    Point U=(Point){p.x,p.y+1,0},D=(Point){p.x,p.y-1,0};
    for(auto q:vec){
        if(q.x<p.x) continue;
        Point v1={q.x,q.y1,q.id1},v2={q.x,q.y2,q.id2};
        if(((U-p)^(v1-p))>0) break;
        if(((D-p)^(v2-p))<0) break;
        if(((U-p)^(v2-p))<=0) U=v2;
        if(((D-p)^(v1-p))>=0) D=v1;
    }
    if(U.id){
        e[p.id].push_back((edge){U.id,distance(U,p)});
        if(U!=D) e[p.id].push_back((edge){D.id,distance(D,p)});
        // cout<<p.id<<" "<<U.id<<" "<<distance(U,p)<<"++\n";
        // if(U!=D) cout<<p.id<<" "<<D.id<<" "<<distance(D,p)<<"++\n";
    }
}
Point S,T;
void make_group(){
    for(auto q:vec){
        make((Point){q.x,q.y1,q.id1});
        make((Point){q.x,q.y2,q.id2});
    }
    make((Point){S.x,S.y,s});
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
    }
    cin>>S.x>>S.y>>T.x>>T.y;
    if(S.x>T.x) swap(S,T);
    double V;
    cin>>V;
    for(int i=1;i<=n-1;i++){
        l[i]=(Line){b[i].x,max(a[i].y,a[i+1].y),min(b[i].y,b[i+1].y),i,n+i};
    }
    s=n+n+1;t=s+1;
    bool f=0;
    for(int i=1;i<=n-1;i++){
        if(l[i].x>=S.x&&l[i].x<=T.x){
            vec.push_back(l[i]);
            // cout<<l[i].x<<" "<<l[i].y1<<" "<<l[i].y2<<"==\n";
        }
        if(l[i].x>S.x&&l[i].x<T.x) f=1;
    }
    if(!f){
        cout<<fixed<<setprecision(6)<<distance(S,T)/V;
        return 0;
    }
    vec.push_back((Line){T.x,T.y,T.y,t,t});
    make_group();
    cout<<fixed<<setprecision(6)<<spfa()/V;
    return 0;
}