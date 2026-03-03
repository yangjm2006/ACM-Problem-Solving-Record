#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int a[N],b[N];
void __(){
    int n;
    cin>>n;
    bool f1=1,f2=1;
    a[0]=b[0]=-1;
    for(int i=1;i<=n;i++) b[i]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) f1=0;
        int x=a[i],cnt=0;
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                cnt++;
                b[i]=j;
            }
            while(x%j==0) x/=j;
        }
        if(x!=1){
            cnt++;
            b[i]=x;
        }
        if(cnt>=2) f2=0;
        if(b[i]<b[i-1]) f2=0;
        // cout<<a[i]<<" "<<cnt<<" "<<b[i]<<"!!!\n";
    }
    if(f1||f2) cout<<"Bob\n";
    else cout<<"Alice\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}