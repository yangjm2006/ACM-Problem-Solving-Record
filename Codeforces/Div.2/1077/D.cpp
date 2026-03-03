// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// const ll INF=1e18;
// void solve(){
//     ll a,b,ans1,ans2,minn=INF;
//     cin>>a>>b;
//     bool f=0;
//     if(a<b){
//         swap(a,b);
//         f=1;
//     }
//     for(int k=0;k<=40;k++){
//         ll cal;
//         if((1ll<<k)>=a){
//             cal=(1ll<<k)-a;
//             if(cal<minn){
//                 ans1=(1ll<<k);
//                 ans2=b;
//             }
//         }else if((1ll<<k)<=b){

//         }else{
//             cal=(1ll<<k)-b+(1ll<<k);
//             if(cal<minn){
//                 ans1=a&(~(1ll<<k));
//                 ans2=(1ll<<k);
//             }
//         }
//         cal=(a&((1ll<<k)-1))&b;
//         if(cal<minn){
//             ans1=a;
//             ans2=;
//         }
//     }
//     if(f) swap(ans1,ans2);
//     cout<<ans1<<" "<<ans2<<'\n';
// }
// int main(){
//     int T;
//     cin>>T;
//     while(T--) solve();
//     return 0;
// }