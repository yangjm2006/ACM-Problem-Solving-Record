#include<bits/stdc++.h>
std::string spt(std::string s,int b,int e){
    std::string res="";
    for(int i=b;i<=e;i++) res+=s[i];
    return res;
}
void solve(){
    std::set<std::string> st;
    int n;
    std::cin>>n;
    std::vector<std::string> s(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>s[i];
        st.insert(s[i]);
    }
    for(int i=1;i<=n;i++){
        bool f=0;
        for(int j=0;j<s[i].size()-1;j++) if(st.find(spt(s[i],0,j))!=st.end()&&st.find(spt(s[i],j+1,s[i].size()-1))!=st.end()) f=1;
        std::cout<<f;
    }
    std::cout<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}