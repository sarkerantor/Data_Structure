#include<bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int vis[200005],sub[200005];
int dfs(int node){
    vis[node]=1;
    sub[node]=1;
    for(int child:v[node]){
        if(!vis[child]){
            sub[node]+=dfs(child);
        }
    }
    return sub[node];
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,a,b;
    cin>>n;
    if(n==1){
        cout<<n;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        bool ok=true;
        for(int val:v[i]){
            if(sub[val]<sub[i]){
                if(sub[val]>n/2)ok=false;
            }
        }
        if((n-sub[i])>n/2)ok=false;
        if(ok){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
