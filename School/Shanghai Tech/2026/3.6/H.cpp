#include<bits/stdc++.h>
using namespace std;
int cnt[2000][50];
bool S[30];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(auto x:s){
            cnt[i][x-'a'+1]++;
            S[x-'a'+1]=1;
        }
    }
    for(int i=1;i<=26;i++){
        bool vis[2000]={0},f=1;
        for(int j=1;j<=n;j++){
            if(vis[cnt[j][i]]){
                f=0;
                break;
            }
            vis[cnt[j][i]]=1;
        }
        if(f){
            cout<<"YES\n";
            for(int j=1;j<=26;j++) if(S[j]){
                if(i!=j) cout<<char('a'+j-1);
            }
            cout<<char('a'+i-1);
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
	return 0;
} 