#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0,n,t,lst=-100;
    cin>>n>>t;
    for(int i=1,x;i<=n+1;i++){
        if(i==n+1) x=t;
        else cin>>x;
        if(x>=lst+100){
            ans+=x-lst-100;
            lst=x;
        }
    }
    cout<<ans;
    return 0;
}