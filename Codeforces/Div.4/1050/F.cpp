#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int INF=1e9;
int T,n;
vector<int> v[N];
set<int> st;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        st.clear();
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x;i<=n;i++){
            cin>>x;
            v[i].push_back(x);
            st.insert(i);
            for(int j=1;j<=v[i][0];j++){
                cin>>x;
                v[i].push_back(x);
            }
        }
        int lst=0,l=1;
        while(!st.empty()){
            set<int> car;int minn=INF;
            for(auto x:st){
                if(v[x][l]<minn){
                    car.clear();
                    car.insert(x);
                    minn=v[x][l];
                }else if(v[x][l]==minn){
                    car.insert(x);
                }
            }
            int nw=0;
            while(car.size()!=1){
                l++;int minn=INF;
                for(auto x:car){
                    if(v[x][0]<l){
                        nw=x;
                        break;
                    }
                    else minn=min(minn,v[x][l]);
                }
                if(nw) break;
                vector<int> vec;
                for(auto x:car){
                    if(minn<v[x][l]) vec.push_back(x);
                }
                for(auto x:vec){
                    car.erase(x);
                }
            }
            if(car.size()==1) nw=*car.begin();
            for(int i=lst+1;i<=v[nw][0];i++){
                cout<<v[nw][i]<<" ";
            }
            lst=v[nw][0];l=lst+1;
            vector<int> vec;
            for(auto x:st){
                if(v[x][0]<l) vec.push_back(x);
            }
            for(auto x:vec){
                st.erase(x);
            }
        }
        cout<<'\n';
    }
    return 0;
}
/*
4
1
3 5 2 7
2
2 2 9
3 3 1 4
3
1 5
2 5 1
2 5 2
3
3 4 4 9
7 7 6 5 4 3 2 1
4 2 4 5 1

*/