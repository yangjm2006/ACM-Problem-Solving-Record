#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
bool vis[N],st[20][N];
int n;
int lg[N+100];
bool get(int l,int r){
    if(r>n) r=n;
    int k=lg[r-l+1];
    return (st[k][l]|st[k][r-(1<<k)+1]);
}
void __(){
    string s;
    cin>>s;
    n=s.size();
    for(int i=1;i<=n;i++) st[0][i]=vis[i]=s[n-i]-'0';
    for(int k=1;k<=lg[n];k++){
        for(int i=1;i<=(n-(1<<k-1));i++){
            st[k][i]=(st[k-1][i]|st[k-1][i+(1<<k-1)]);
        }
    }
    // for(int k=0;k<=3;k++){
    //     for(int i=1;i<=n;i++) cout<<st[k][i]<<" ";
    //     cout<<'\n';
    // }
    // for(int i=1;i<=n;i++) cout<<vis[i];cout<<'\n';
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=i;j<=min(i+20,n);j++){
            if(vis[j]){
                res+=(1<<(j-i));
                if(j-i+1==res){
                    ans++;
                }else if(i+res-1<=n&&i+res-1>=j+1){
                    if(get(j+1,i+res-1)==0) ans++;
                    // cout<<i<<" "<<i+res-1<<"!!\n";
                }
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<=N;i++) lg[i]=lg[i/2]+1;
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}