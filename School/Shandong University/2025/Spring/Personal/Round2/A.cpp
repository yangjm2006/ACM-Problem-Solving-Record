#include<bits/stdc++.h>
using namespace std;
int h1,m1,h2,m2;
int main(){
    char c;
    cin>>h1>>c>>m1>>h2>>c>>m2;
    if((h1+h2)%2==0){
        printf("%02d:%02d",(h1+h2)/2+(m1+m2)/2/60,(m1+m2)/2%60);
    }else{
        printf("%02d:%02d",(h1+h2)/2+(m1+m2+60)/2/60,(m1+m2+60)/2%60);
    }
    return 0;
}