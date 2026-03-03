#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct node{
    int h,w,id;
}a[N],b[N];
bool cmp1(node x,node y){
    return x.h>y.h;
}
bool cmp2(node x,node y){
    return x.w>y.w;
}
pair<int,int> ans[N];
int H,W,n;
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>H>>W>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].w;
        b[i].h=a[i].h;
        b[i].w=a[i].w;
        a[i].id=b[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    int tp1=1,tp2=1;
    while(tp1<=n&&tp2<=n){
        while(tp1<=n&&vis[a[tp1].id]){
            tp1++;
        }
        if(tp1<=n&&a[tp1].h==H){
            ans[a[tp1].id]=make_pair(1,W-a[tp1].w+1);
            W-=a[tp1].w;
            vis[a[tp1].id]=1;
            tp1++;
        }
        while(tp2<=n&&vis[b[tp2].id]){
            tp2++;
        }
        if(tp2<=n&&b[tp2].w==W){
            ans[b[tp2].id]=make_pair(H-b[tp2].h+1,1);
            H-=b[tp2].h;
            vis[b[tp2].id]=1;
            tp2++;
        }
        // cout<<tp1<<" "<<tp2<<"++\n";
    }
    for(int i=1;i<=n;i++) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    return 0;
}