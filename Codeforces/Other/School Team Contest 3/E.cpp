#include<bits/stdc++.h>
int n;
std::vector<std::string> v1[30],v2[30],ans;
int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        v1[int(s[0]-'A'+1)].push_back(s);
    }
    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        v2[int(s[0]-'A'+1)].push_back(s);
    }
    for(int i=1;i<=26;i++){
        std::sort(v1[i].begin(),v1[i].end());
        std::sort(v2[i].begin(),v2[i].end());
    }
    for(int i=1;i<=26;i++){
        std::vector<std::string> vec1,vec2;
        for(;v1[i].size()&&v2[i].size();){
            vec1.push_back(*v1[i].begin());
            v1[i].erase(v1[i].begin());
            vec2.push_back(*v2[i].begin());
            v2[i].erase(v2[i].begin());
        }
        for(int j=1;j<=26;j++){
            if(i==j) continue;
            for(;v1[i].size()&&v2[j].size()>v1[j].size();){
                vec1.push_back(*v1[i].begin());
                v1[i].erase(v1[i].begin());
                vec2.push_back(*v2[j].begin());
                v2[j].erase(v2[j].begin());
            }
        }
        std::sort(vec1.begin(),vec1.end());
        std::sort(vec2.begin(),vec2.end());
        for(int i=0;i<vec1.size();i++) ans.push_back(vec1[i]+" "+vec2[i]);
    }
    for(int i=0;i<n-1;i++) std::cout<<ans[i]<<", ";
    std::cout<<ans[n-1];
    return 0;
}