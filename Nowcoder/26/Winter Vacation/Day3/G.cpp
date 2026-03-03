#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cal(ll x){
    ll cnt=0;
    while(x>=10ll){
        cnt++;
        ll tmp=1;
        while(x){
            tmp*=x%10;
            x/=10;
        }
        x=tmp;
    }
    return cnt;
}
int main(){

    return 0;
}