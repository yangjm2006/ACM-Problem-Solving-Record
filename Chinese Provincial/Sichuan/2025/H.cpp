    #include<bits/stdc++.h>
    using namespace std;

    void solve(){
        int x,y,X,Y;
        cin>>x>>y>>X>>Y;
        if(x==X&&y==Y){
            cout<<0;
            return;
        }
        int dx=abs(x-X);
        int dy=abs(y-Y);
        int n1=(dx+1)/2;
        int n2=(dy+1)/2;
    int ans=max(n1,n2);
    if(ans==1){
        if(x==X||y==Y)cout<<2;
    else{
        cout<<1;
    }    return;

    }
    cout<<ans;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            solve();
            cout<<endl;
        }
        // int n;
        // for(int i=1;i<=n;i++){
        //     string s;
        //     cin>>s;
        // }
        return 0;
    }
    /*

    3
    1 2 1 2
    1 1 3 4
    1 1 98 98

    */