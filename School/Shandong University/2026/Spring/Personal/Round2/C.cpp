#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct node{
    int l,r,id;
    bool operator < (const node &_) const{
        return l<_.l;
    };
}a[N];
int ans[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    int R=a[1].r;
    for(int i=1;i<=n;i++){
        if(a[i].l<=R){
            R=max(R,a[i].r);
        }else{
            for(int j=1;j<=i-1;j++) ans[a[j].id]=1;
            for(int j=i;j<=n;j++) ans[a[j].id]=2;
            for(int j=1;j<=n;j++) cout<<ans[j]<<" ";
            cout<<'\n';
            return;
        }
    }
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}