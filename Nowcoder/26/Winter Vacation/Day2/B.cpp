#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N];
void __(){
    int n;
    cin>>n;
    int maxx=-1,cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>maxx){
            maxx=a[i];
            cnt=1;
        }else if(a[i]==maxx){
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==maxx){
            if(cnt%2==1) cout<<'1';
            else cout<<'0';
        }else{
            if(cnt%2==1) cout<<'0';
            else cout<<'1';
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}