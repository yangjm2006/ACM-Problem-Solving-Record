#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
struct node{
    char d;
    int x;
};

void solve(){
    cin>>n;
    char s;
    int lstx = 0;

    char d;
    int x;
    vector<node>v;
    for(int i=1;i<=n;i++){
        cin>>d>>x;
        if(lstx==0){
            node tmp;
            tmp.d=d;
            tmp.x=x;
            v.emplace_back(tmp);
            lstx = x;
            s = d;
        }
        else{
            if(s=='N'){
                node tmp;
                if(d=='E'){
                    tmp.d='R';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                else{
                    tmp.d='L';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                tmp.d='Z';
                tmp.x=x;
                v.emplace_back(tmp);
            }
            else if(s=='S'){
                node tmp;
                if(d=='E'){
                    tmp.d='L';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                else{
                    tmp.d='R';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                tmp.d='Z';
                tmp.x=x;
                v.emplace_back(tmp);
            }
            else if(s=='E'){
                node tmp;
                if(d=='N'){
                    tmp.d='L';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                else{
                    tmp.d='R';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                tmp.d='Z';
                tmp.x=x;
                v.emplace_back(tmp);

            }
            else if(s=='W'){
                node tmp;
                if(d=='S'){
                    tmp.d='L';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                else{
                    tmp.d='R';
                    tmp.x=0;
                    v.emplace_back(tmp);
                }
                tmp.d='Z';
                tmp.x=x;
                v.emplace_back(tmp);
            }
        lstx = x;
        s = d;
        }
    }
    cout<<v.size()<<" "<<v[0].d<<'\n';
    cout<<"Z "<<v[0].x<<'\n';
    for(int i=1;i<v.size();i++){
        if(v[i].x==0)cout<<v[i].d<<'\n';
        else cout<<v[i].d<<" "<<v[i].x<<'\n';
    }
}

int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}