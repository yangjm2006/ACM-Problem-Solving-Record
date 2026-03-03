#include<bits/stdc++.h>
int Alice(std::string S){
    int n=S.size(),res=0;
    for(int i=0;i<n;i++) if(S[i]=='1') res^=i+1;
    return res;
}
int Bob(std::string T, int X){
    int n=T.size();
    for(int i=0;i<n;i++) if(T[i]=='1') X^=i+1;
    return X;
}