#include<bits/stdc++.h>
using namespace std;
bool vis[30][30];
int a[30];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=0;
    int L=1;
    for(int u=1;u<=n;u++){
        int v=0;
        for(;;){
            int l=L,r=(1<<n),len;
            while(l<r){
                int mid=l+r>>1;
                cout<<"? "<<mid<<'\n';
                cin>>len;
                for(int j=1;j<=len;j++){
                    cin>>a[j];
                }
                for(int j=1;j<len;j++){
                    vis[a[j]][a[j+1]]=1;
                }
                if((len!=0&&a[1]<u)||(len==1&&a[1]==u)||(len>=2&&a[1]==u&&a[2]<=v)) l=mid+1;
                else r=mid;
            }
            cout<<"? "<<l<<'\n';
            cin>>len;
            for(int j=1;j<=len;j++){
                cin>>a[j];
            }
            for(int j=1;j<len;j++){
                vis[a[j]][a[j+1]]=1;
            }
            if(len<2||a[1]!=u||a[2]<=v) break;
            v=a[2];
            L=l;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(vis[i][j]) cnt++;
    cout<<"! "<<cnt<<'\n';
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(vis[i][j]) cout<<i<<" "<<j<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}