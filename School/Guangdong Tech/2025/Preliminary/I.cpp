#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long ans;
int num[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        num[x]++;
        ans+=i-num[x];
    }
    cout<<ans;
    return 0;
}