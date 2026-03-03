#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N=4;
int a[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    s="0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int now=0;
    string s1="";
    for(int i=0;i<s.size();i++){
        if(now==0){
            if(s[i]=='0') now=3;
            else if(s[i]=='1') now=0;
            else if(s[i]=='2') now=1;
            else if(s[i]=='3') now=2;
            else if(s[i]=='4') now=1;
            else if(s[i]=='5') now=3;
        }
        else if(now==1){
            if(s[i]=='0') now=2;
            else if(s[i]=='1') now=3;
            else if(s[i]=='2') now=0;
            else if(s[i]=='3') now=1;
            else if(s[i]=='4') now=2;
            else if(s[i]=='5') now=0;
        }
        else if(now==2){
            if(s[i]=='0') now=1;
            else if(s[i]=='1') now=2;
            else if(s[i]=='2') now=3;
            else if(s[i]=='3') now=0;
            else if(s[i]=='4') now=3;
            else if(s[i]=='5') now=1;
        }
        else if(now==3){
            if(s[i]=='0') now=0;
            else if(s[i]=='1') now=1;
            else if(s[i]=='2') now=2;
            else if(s[i]=='3') now=3;
            else if(s[i]=='4') now=0;
            else if(s[i]=='5') now=2;
        }
        s1+=char('0' + now);
    }
    cout<<s1;
    return 0;
}