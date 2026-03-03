#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=1e9;
int T,n,a[N];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int minn=INF,s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            minn=min(minn,a[i]);
            s+=a[i];
        }
        cout<<s-minn*n<<'\n';
    }
    return 0;
}