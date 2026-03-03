#include<bits/stdc++.h>
const int N=4e5+100;
int a[N],n,m;
std::vector<int> v[N];
bool vis[N];
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    std::cin>>n;
    for(int i=1;i<=3*n;i++){
        std::cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x1,x2,x3;
        std::cin>>x1>>x2>>x3;
        v[x1].push_back(x2);v[x1].push_back(x3);
        v[x2].push_back(x1);v[x2].push_back(x3);
        v[x3].push_back(x1);v[x3].push_back(x2);
    }
    int y;
    std::cin>>y;
    for(int i=1;i<=3*n;i++){
        if(a[i]==y){
            if(vis[a[i]]){
                for(int j=1;j<=3*n;j++) if(j!=y) std::cout<<j<<" ";
            }else{
                for(auto x:v[a[i]]) vis[x]=1;
                for(int j=1;j<=std::max(v[a[i]][0],v[a[i]][1]);j++) if(vis[j]) std::cout<<j<<" ";
                for(int j=1;j<=3*n;j++){
                    if(!vis[j]){
                        if(j!=y) std::cout<<j<<" ";
                    }else if(j>std::max(v[a[i]][0],v[a[i]][1])) std::cout<<j<<" ";
                }
            }
            return 0;
        }
        if(vis[a[i]]) continue;
        vis[a[i]]=1;
        for(auto x:v[a[i]]) vis[x]=1;
    }
    return 0;
}