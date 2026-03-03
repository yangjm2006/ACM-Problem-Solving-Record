#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N],b[N],cnt1,cnt2,T;
string s1,s2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s1>>s2;
        cnt1=cnt2=0;
        if(s1[0]!=s2[0]){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<s1.size();i++){
            if(i>0&&s1[i]==s1[i-1]){
                a[cnt1]++;
            }else a[++cnt1]=1;
        }
        for(int i=0;i<s2.size();i++){
            if(i>0&&s2[i]==s2[i-1]){
                b[cnt2]++;
            }else b[++cnt2]=1;
        }
        if(cnt1!=cnt2) cout<<"NO\n";
        else{
            bool f=1;
            for(int i=1;i<=cnt1;i++){
                if(b[i]<a[i]||b[i]>a[i]*2){
                    f=0;
                    break;
                } 
            }
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}