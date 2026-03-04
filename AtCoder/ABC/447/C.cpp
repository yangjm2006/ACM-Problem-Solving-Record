#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s,t;
    cin>>s>>t;
    s='!'+s+'!';t='!'+t+'!';
    int tp1=0,tp2=0,n=s.size(),m=t.size(),ans=0;
    while(tp1<n&&tp2<m){
        int cnt1=0,cnt2=0;
        while(tp1<n&&s[tp1]=='A'){
            tp1++;
            cnt1++;
        }
        while(tp2<m&&t[tp2]=='A'){
            tp2++;
            cnt2++;
        }
        ans+=abs(cnt1-cnt2);
        if(tp1<n&&tp2<m){
            if(s[tp1]==t[tp2]){
                tp1++;tp2++;
            }else{
                cout<<"-1\n";
                return 0;
            }
        }
        // cout<<tp1<<" "<<tp2<<"++\n";
    }
    if(tp1!=n||tp2!=m) cout<<"-1\n";
    else cout<<ans<<'\n';
    return 0;
}