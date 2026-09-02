#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,b; cin>>n>>b;
    if(n==0){
        cout<<0<<'\n';
        return 0;
    }
    string chars="0123456789ABCDEFGHIJKLMNOPQRSTUV";
    string ans="";
    while(n>0){
        int d=n%b;
        ans+=chars[d];
        n=n/b;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
    return 0;
}