#include<bits/stdc++.h>
const int N=200;
int a,b,c,d,n,x[N],mp[N][N],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void work(){
    int cnt=(std::min(b,d)&1)^(d>b),tmp=1;
    for(int i=1;i<=std::max(b,d);i++){
        cnt++;
        if(cnt&1){
            for(int j=1;j<=a+c;j++){
                if(mp[i][j]==-1) continue;
                x[tmp]--;
                mp[i][j]=tmp;
                if(x[tmp]==0) tmp++;
            }
        }else{
            for(int j=a+c;j>=1;j--){
                if(mp[i][j]==-1) continue;
                x[tmp]--;
                mp[i][j]=tmp;
                if(x[tmp]==0) tmp++;
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    std::cin>>a>>b>>c>>d>>n;
    for(int i=1;i<=std::max(b,d);i++){
        for(int j=1;j<=a+c;j++) mp[i][j]=-1;
    }
    for(int i=1;i<=b;i++) for(int j=1;j<=a;j++) mp[i][j]=0;
    for(int i=1;i<=d;i++) for(int j=a+1;j<=a+c;j++) mp[i][j]=0;
    for(int i=1;i<=n;i++) std::cin>>x[i];
    work();
    std::cout<<"YES\n";
    for(int i=1;i<=std::max(b,d);i++){
        for(int j=1;j<=a+c;j++) std::cout<<(mp[i][j]==-1?'.':char('a'+mp[i][j]-1));
        std::cout<<'\n';
    }
    return 0;
}