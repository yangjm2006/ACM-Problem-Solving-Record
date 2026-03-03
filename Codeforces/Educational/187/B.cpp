#include<bits/stdc++.h>
using namespace std;
int a[30],n;
bool check(int y){
    int s1=y,s2=0;
    int x=s1;
    while(x){
        s2+=x%10;
        x/=10;
    }
    return s1==s2;
}
void __(){
    string s;
    cin>>s;
    n=s.size();
    int sum=0;
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
        sum+=a[i];
        if(i==1) a[i]--;
    }
    sort(a+1,a+1+n,greater<int>());
    if(check(sum)){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++){
        sum-=a[i];
        if(check(sum)){
            cout<<i<<'\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}