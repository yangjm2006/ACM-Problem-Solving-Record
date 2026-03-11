#include<bits/stdc++.h>
using namespace std;
const int M=1e7;
const int N=1e4;
bool vis[M];
int a[N];
void __(){
    int n;
    cin>>n;
    cout<<n-1<<'\n';
    for(int i=1;i<n;i++){
        int w;
        for(int j=1;;j++){
            if(vis[j]==0){
                w=j;    
                a[i]=w;
                int res=0;bool f=1;
                for(int j=i;j>=1;j--){
                    res+=a[j];
                    if(vis[res]){
                        f=0;
                    }
                }
                if(f) break;
            }
        }
        int res=0;
        for(int j=i;j>=1;j--){
            res+=a[j];
            vis[res]=1;
        }
        cout<<i<<" "<<i+1<<" "<<w<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
	return 0;
} 