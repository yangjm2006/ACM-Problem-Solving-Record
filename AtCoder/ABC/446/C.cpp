#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,d,a[N],b[N];
void __(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int tp=1;
    for(int i=1;i<=n;i++){
        while(b[i]){
            if(a[tp]>b[i]){
                a[tp]-=b[i];
                b[i]=0;
            }else{
                b[i]-=a[tp];
                tp++;
            }
        }
        tp=max(tp,i-d+1);
    }
    int sum=0;
    for(int i=tp;i<=n;i++) sum+=a[i];
    cout<<sum<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}