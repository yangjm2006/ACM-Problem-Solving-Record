#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,a[N],s[N];
bool check(int tim){
    int R=1,cnt=0;
    for(;;){
        if(R>n) break;
        bool f=0;
        for(int i=R;i<=n;i++){
            if(a[i]){
                R=i;
                f=1;
                break;
            }
        }
        if(!f) break;
        cnt++;
        for(int t=1;t<=tim;t++){
            R=s[R];
            if(R>=n||R<=s[R]) break;
        }
        R++;
    }
    return cnt<=k;
}
void __(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int tmp=0;
    for(int i=1;i<=n;i++) if(a[i]) tmp++;
    if(tmp==k){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++){
        s[i]=max(s[i-1],a[i]+i);
    }
    // for(int i=1;i<=n;i++) cout<<s[i]<<" ";cout<<"-------\n";
    int l=1,r=n+1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==n+1) cout<<"-1\n";
    else cout<<l<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}