#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string res;
    int n;
    cin>>res>>n;
    if(n==1) {
        cout<<res<<'\n';
        return 0;
    }
    string row[1000];
    int j=0,dir=1;
    for(int i=0;i<res.size();i++){
        row[j]+=res[i];
        if(j==0) dir=1;
        if(j==n-1) dir=-1;
        j+=dir;
    }
    for(int i=0;i<n;i++){
        cout<<row[i];
    }
    cout<<'\n';
    return 0;
}