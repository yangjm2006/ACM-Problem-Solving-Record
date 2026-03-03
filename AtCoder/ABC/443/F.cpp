#include<bits/stdc++.h>
using namespace std;
const int N=3e7+100;
bool vis[N];
int lst[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    queue<int> q;q.push(0);
    while(!q.empty()){
        int u=q.front()/10,c=q.front()%10;q.pop();
        if(u==0&&c!=0){
            u=u*10+c;
            stack<int> ans;
            while(u!=0){
                ans.push(u%10);
                u=lst[u];
            }
            while(!ans.empty()){
                cout<<ans.top();
                ans.pop();
            }
            return 0;
        }
        for(int x=max(1,c);x<=9;x++){
            int v=(u*10+x)%n;
            if(vis[v*10+x]==0){
                lst[v*10+x]=u*10+c;
                vis[v*10+x]=1;
                q.push(v*10+x);
            }
        }
    }
    cout<<"-1";
    return 0;
}