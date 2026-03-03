#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int x,y;
}c[15];
// struct node2{
//     int x,yl,yr;
// };

void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>c[i].x>>c[i].y;
    }
    for(int j=0;j<(1<<k);j++){
        // cout<<" ! "<<j<<" ";
        if(k==0){
            cout<<m-1<<' ';
            continue;
        }
        // int last=-1;
        // int wx;
        // int ans = 0;
        // int last_len = 0;
        bool op = 1;
        vector<pair<int,int>>duan;

        for(int i=1;i<=k;i++){
            int ths = (j>>(i-1))&1;
            ths^=1;
            if((ths==1&&c[i].x==1)||(ths==0&&c[i].x==n)){
                cout<<"-1 ";
                op=0;
                break;
            }
            if(ths==1){
                duan.emplace_back(make_pair(1,c[i].x-1));
            }
            else if(ths==0){
                duan.emplace_back(make_pair(c[i].x+1,n));
            }
            if(duan.size()>1){
                int ths=duan.size()-1;
                if(c[i].y==c[i-1].y+1){
                    if(duan[ths].second<duan[ths-1].first||duan[ths].first>duan[ths-1].second){
                        cout<<"-1 ";
                        op=0;
                        break;
                    }
                }
            }
        }
        if(op){
            int lastl=duan[0].first,lastr=duan[0].second;
            int ans = m-1;
                for(int i=1;i<duan.size();i++){
                    if(lastr<duan[i].first){
                        ans+=duan[i].first-lastr;
                        lastl=duan[i].first;
                        lastr=duan[i].first;
                    }
                    else if(lastl>duan[i].second){
                        ans+=lastl-duan[i].second;
                        lastl=duan[i].second;
                        lastr=duan[i].second;
                    }
                    else{
                        lastl=max(lastl,duan[i].first);
                        lastr=min(lastr,duan[i].second);
                    }
                }
                cout<<ans<<" ";
            }
        
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
/*
 3
 3 6
 2
 3 4
 2 5
 3 4
 1
 1 2
 3 6
 2
 3 2
 1 5
*/