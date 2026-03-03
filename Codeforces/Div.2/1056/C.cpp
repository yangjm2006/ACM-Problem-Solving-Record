#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,n,a[N],s[N];
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        bool f1=0,f2=0,f3=0;
        for(int i=1;i<=n-1;i++) if(a[i]>a[i+1]+1||a[i]<a[i+1]-1) f3=1;
        if(f3){
            cout<<"0\n";
            continue;
        }
        int pos;
        for(int i=1;i<=n-1;i++) if(a[i]!=a[i+1]){
            f1=1;
            pos=i;
            break;
        }
        if(f1==0){
            for(int i=1;i<=n;i++) vis[i]=i&1;
            for(int i=1;i<=n;i++) s[i]=s[i-1]+vis[i];
            f2=0;
            for(int i=1;i<=n;i++){
                if((s[i-1]+(n-i-(s[n]-s[i]))+1)!=a[i]){
                    f2=1;
                }
            }
            int cnt=0;
            cnt+=!f2;
            f2=0;
            for(int i=1;i<=n;i++) vis[i]=vis[i]^1;
            for(int i=1;i<=n;i++) s[i]=s[i-1]+vis[i];
            f2=0;
            for(int i=1;i<=n;i++){
                if((s[i-1]+(n-i-(s[n]-s[i]))+1)!=a[i]){
                    f2=1;
                }
            }
            cnt+=!f2;
            cout<<cnt<<"\n";
            continue;
        }
        if(a[pos]==a[pos+1]+1) vis[pos]=vis[pos+1]=0;
        else vis[pos]=vis[pos+1]=1;
        for(int i=pos+2;i<=n;i++){
            if(a[i]==a[i-1]){
                vis[i]=vis[i-1]^1;
            }else if(a[i]==a[i-1]+1){
                vis[i]=1;
            }else{
                vis[i]=0;
            }
        }
        for(int i=pos-1;i>=1;i--){
            if(a[i]==a[i+1]){
                vis[i]=vis[i+1]^1;
            }else if(a[i]==a[i+1]-1){
                vis[i]=1;
            }else{
                vis[i]=0;
            }
        }
        for(int i=1;i<=n;i++) s[i]=s[i-1]+vis[i];
        f2=0;
        for(int i=1;i<=n;i++){
            if((s[i-1]+(n-i-(s[n]-s[i]))+1)!=a[i]){
                f2=1;
            }
        }
        if(f2) cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}