#include<bits/stdc++.h>
using namespace std;
const int N=100;
string s;
int a[N],p[N],cnt[N],n;
bool vis[N];
vector<int> v[5];
void work(int id,char c){
    memset(vis,0,sizeof(vis));
    int nw=p[id];
    while(!vis[nw]){
        vis[nw]=1;
        if(s[nw]==c) v[id].push_back(cnt[id]);
        nw=a[nw];
        cnt[id]++;
    }
}
char ch[5]={'0','T','T','P','C'};
int main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=4;i++) cin>>p[i];
    for(int i=1;i<=4;i++){
        work(i,ch[i]);
    }
    // for(int i=1;i<=)
    return 0;
}