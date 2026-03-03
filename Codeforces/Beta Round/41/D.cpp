#include<bits/stdc++.h>
using namespace std;
int a[40],n;
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    a[1]=1;a[2]=2;
    for(int o=3;o<=n;o++){
        bool vis[2000]={0};
        for(int i=1;i<o;i++) for(int j=i+1;j<o;j++) for(int k=1;k<o;k++)
            if(a[i]+a[j]-a[k]>0) vis[a[i]+a[j]-a[k]]=1;
        for(int i=1;i<=1000;i++) if(!vis[i]){
            a[o]=i;
            break;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout<<"0 ";
            }else{
                cout<<a[i]+a[j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}