#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
char get(char a,char b){
    bool vis[300]={0};
    vis[a]=1;vis[b]=1;
    for(char c='a';c<='z';c++) if(!vis[c]) return c; 
}
void __(){
    int n,k;
    cin>>n>>k;
    k=n-k;
    string s1,s2;
    cin>>s1>>s2;
    int dif=0,sam=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]) dif++;
        else sam++;
    }
    if(k>dif/2+sam){
        cout<<"-1";
        return;
    }
    string ans;
    for(int i=0;i<n;i++) ans+='0';
    for(int i=0;i<n;i++){
        if(k==0) break;
        if(s1[i]==s2[i]){
            ans[i]=s1[i];
            k--;
        }
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        if(tmp==k*2) break;
        if(s1[i]!=s2[i]){
            tmp++;
            if(tmp%2==1) ans[i]=s1[i];
            else ans[i]=s2[i];
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]=='0') ans[i]=get(s1[i],s2[i]);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}