#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int N=2e5+100;
#define inf 100000000000000
int T,n;

ll gcd(ll a, ll b){
    if(a % b == 0){
        return b;
    }else{ 
        return gcd(b, a%b);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        bool flag = false;

        ll ansc = inf;
        ll ansd = inf;

        for(ll i = 1; i <= 1000000000; i *= 2){
            for(ll j = i; j <= inf; j *= 5){
                if(b == j){
                    flag = true;
                    break;
                }
                ll k = a * j  / b;
                if(a * j > k * b){
                    k++;
                }
                
                while(k % 2 == 0 || k % 5 == 0)k++;

                ll c, d, g;
                
                d = b * j;
                c = k * b - a * j;
                g = gcd(c, d);
                c /= g;
                d /= g;
                if(d > 1000000000){
                    continue;
                }
                if(c < ansc){
                    ansc = c;
                    ansd = d;
                }
                
                k += 2;

                d = b * j;
                c = k * b - a * j;
                g = gcd(c, d);
                c /= g;
                d /= g;
                if(d > 1000000000){
                    continue;
                }
                if(c < ansc){
                    ansc = c;
                    ansd = d;
                }

                k += 2;

                d = b * j;
                c = k * b - a * j;
                g = gcd(c, d);
                c /= g;
                d /= g;
                if(d > 1000000000){
                    continue;
                }
                if(c < ansc){
                    ansc = c;
                    ansd = d;
                }

                k += 2;

                d = b * j;
                c = k * b - a * j;
                g = gcd(c, d);
                c /= g;
                d /= g;
                if(d > 1000000000){
                    continue;
                }
                if(c < ansc){
                    ansc = c;
                    ansd = d;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout << "0 1\n";
        }else{
            cout << ansc << " " << ansd << '\n';
        }
    }
    return 0;
}
/*
4
1 2
2 3
3 7
19 79
*/