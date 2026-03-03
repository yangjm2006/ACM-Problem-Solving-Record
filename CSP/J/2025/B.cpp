#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,t;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    t=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++) if(t==a[i]){
        t=i;
        break;
    }
    cout<<(t-1)/n+1<<" "<<(((t-1)/n+1)%2?(t-1)%n+1:(n-(t-1)%n));
    return 0;
}