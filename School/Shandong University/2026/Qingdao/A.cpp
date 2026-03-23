#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
ll n, m;
string s[N];
int main(){
    cin >> n >> m;
    char ch=getchar();
    for(ll i = 1; i <= n; i++){
        getline(cin, s[i]);
    }
    ll pos = 0;
    for(ll i = 1; i <= m; i++){
        ll x;
        cin >> x;
        pos += x+1;
        pos--;
        pos %= n;
        pos++;
        cout << s[pos] << '\n';
    }
    return 0;
}