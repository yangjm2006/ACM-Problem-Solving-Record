#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int l=1,r=1000;
        while(l<r){
            int mid1=(l*2+r)/3,mid2=(l+r*2)/3;
            cout<<"? "<<mid1<<" "<<mid2<<"\n";
            cout.flush();
            int s;
            cin>>s;
            if(s==mid1*mid2) l=mid2+1;
            else if(s==mid1*(mid2+1)) l=mid1+1,r=mid2;
            else r=mid1;
        }
        cout<<"! "<<l<<"\n";
        cout.flush();
    }
    return 0;
}