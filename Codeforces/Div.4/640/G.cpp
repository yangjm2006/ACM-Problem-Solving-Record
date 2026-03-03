#include<bits/stdc++.h>
using namespace std;
int T,n,d[4]{-1,1,2,-2};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=3) cout<<"-1\n";
        else{
            if(n%4==0){
                for(int i=1;i<=n;i++){
                    cout<<i+d[i%4]<<" ";
                }
                cout<<'\n';
            }else if(n%4==1){
                cout<<"2 4 1 5 3 ";
                for(int i=6;i<=n;i++){
                    cout<<i+d[(i-1)%4]<<" ";
                }
                cout<<'\n';
            }else if(n%4==2){
                cout<<"2 4 6 3 1 5 ";
                for(int i=7;i<=n;i++){
                    cout<<i+d[(i-2)%4]<<" ";
                }
                cout<<'\n';
            }else{
                cout<<"2 6 4 1 3 5 7 ";
                for(int i=8;i<=n;i++){
                    cout<<i+d[(i-3)%4]<<" ";
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}