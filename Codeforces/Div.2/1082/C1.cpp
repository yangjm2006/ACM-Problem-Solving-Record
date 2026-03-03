#include<bits/stdc++.h>
using namespace std;
void __(){
    int n;
    cin>>n;
    int maxx=-1,minn=1e9,cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>maxx||x<minn){
            cnt++;
            maxx=x+1;
            minn=x+1;
        }else{
            maxx=x+1;
        }
    }
    cout<<cnt<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}