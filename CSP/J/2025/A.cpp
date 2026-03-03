#include<bits/stdc++.h>
using namespace std;

int cnt[10];

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[s[i]-'0']++;
        }
    }    
    
    for(int i = 9; i >= 0; i--){
        for(int j = 1; j <= cnt[i]; j++){
            printf("%d", i);
        }
    }

    return 0;
}