#include<bits/stdc++.h>
using namespace std;
void __(){
    int n,m,d;
    cin>>n>>m>>d;
    int sum=0,tmp;
    for(int i=1;i<=n;i++){
        if(sum>d){
            break;
        }
        tmp=i;
        sum+=m;
    }
    cout<<(n-1)/tmp+1<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}