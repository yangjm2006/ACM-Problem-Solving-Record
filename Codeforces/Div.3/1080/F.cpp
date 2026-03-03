#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4;
ll a[N],b[N],c[N];
vector<int> g1[N],g2[N];
int n,len1[N],len2[N],in1[N],in2[N];
void topo1(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(in1[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:g1[u]){
            len1[v]=max(len1[v],len1[u]+1);
            in1[v]--;
            if(in1[v]==0) q.push(v);
        }
    }
}
void topo2(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(in2[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:g2[u]){
            len2[v]=max(len2[v],len2[u]+1);
            in2[v]--;
            if(in2[v]==0) q.push(v);
        }
    }
}
void __(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        len1[i]=len2[i]=in1[i]=in2[i]=0;
        g1[i].clear();g2[i].clear();
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        if(a[i]==a[j]&&b[i]==b[j]){
            if(c[i]>c[j]){
                // cout<<i<<" "<<j<<"+\n";
                g1[i].push_back(j);
                in1[j]++;
                g2[j].push_back(i);
                in2[i]++;
            }else if(c[i]<c[j]){
                // cout<<j<<" "<<i<<"+\n";
                g1[j].push_back(i);
                in1[i]++;
                g2[i].push_back(j);
                in2[j]++;
            }
        }else if((b[i]-b[j])*(b[i]-b[j])-4*(a[i]-a[j])*(c[i]-c[j])<0){
            if(a[i]>a[j]){
                // cout<<i<<" "<<j<<"+\n";
                g1[i].push_back(j);
                in1[j]++;
                g2[j].push_back(i);
                in2[i]++;
            }else if(a[i]<a[j]){
                // cout<<j<<" "<<i<<"+\n";
                g1[j].push_back(i);
                in1[i]++;
                g2[i].push_back(j);
                in2[j]++;
            }
        }
    }
    topo1();
    topo2();
    // for(int i=1;i<=n;i++) cout<<len1[i]<<" ";cout<<"+++\n";
    // for(int i=1;i<=n;i++) cout<<len2[i]<<" ";cout<<"---\n";
    for(int i=1;i<=n;i++) cout<<len1[i]+len2[i]+1<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}