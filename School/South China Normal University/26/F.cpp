#include<bits/stdc++.h>
using namespace std;
char to(int x){
    return x?'>':'<';
}
void dne(string &s,string str){
    string p=s,s1=str.substr(0,str.find("v")),s2=str.substr(str.find("v")+1,str.size()-str.find("v")-1);
    // cout<<s1<<" "<<s2<<" -----\n";
    while(p.size()<500){
        s=p;
        if(p.find(s1)==-1) break;
        p=p.replace(p.find(s1),s1.size(),s2);
        // cout<<p<<"?\n";
    }
    // cout<<s<<"!!!!!!!!!!!!!!\n";
}
bool flg;
int cal(string s){
    int cnt=0;
    for(auto c:s)
        if((c=='>')^flg) cnt++;
    return cnt;
}
string get(string x){
    string s="";
    for(char c:x){
        if((c=='1')^flg) s+=">";
        else s+="<";
    }
    return s;
}
void solve(){
    flg=0;
    string s;
    cin>>s;
    cout<<"<v>\n";
    cout.flush();
    dne(s,"<v>");
    string str;
    cin>>str;
    dne(s,str);
    // cout<<s<<"!!!!!!!!!\n";
    flg=(cal(s)==0);
    cout<<get("1")<<"v"<<get("11")<<'\n';
    cout.flush();
    dne(s,get("1")+"v"+get("11"));
    cin>>str;
    dne(s,str);
    int num=cal(s);
    if(num==249||num==250){
        cout<<get("1")<<"v"<<get("1")<<'\n';
    }else if(num==499){
        cout<<get("11")<<"v"<<get("0")<<'\n';
    }else if(num==0){
        cout<<get("00")<<"v"<<get("1")<<'\n';
    }else if(num==1&&s.size()==1){
        cout<<get("1")<<"v"<<get("101")<<'\n';
    }else if(num==1&&s.size()==499){
        cout<<get("00")<<"v"<<get("01")<<'\n';
    }
    cout.flush();
    cin>>str;
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}