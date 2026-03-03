#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cout<<i%n+1<<" ";
    return 0;
}