#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=200005;
vector<int>graph[N];
int parent[N],heavy[N],subtree[N],depth[N],head[N],pos[N];
int curpos=0;
ll basearray[N],segtree[4*N];
int dfs(int node){
    subtree[node]=1;
    heavy[node]=-1;
    int mx=0;
    for(int child:graph[node]){
        if(child==parent[node])continue;
        parent[child]=node;
        depth[child]=depth[node]+1;
        int sz=dfs(child);
        subtree[node]+=sz;
        if(sz>mx){
            mx=sz;
            heavy[node]=child;
        }
    }
    return subtree[node];
}
void decompose(int node,int h){
    head[node]=h;
    pos[node]=++curpos;
    if(heavy[node]!=-1){
        decompose(heavy[node],h);
    }
    for(int child:graph[node]){
        if(child!=parent[node] && child!=heavy[node]){
            decompose(child,child);
        }
    }
}
void update(int node,int l,int r,int idx,ll val){
    if(l==r){
        segtree[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid)update(node*2,l,mid,idx,val);
    else update(node*2+1,mid+1,r,idx,val);
    segtree[node]=segtree[node*2]+segtree[node*2+1];
}
void build(int node,int l,int r){
    if(l==r){
        segtree[node]=basearray[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    segtree[node]=segtree[node*2]+segtree[node*2+1];
}
ll query(int node,int st,int end,int l,int r){
    if(l<=st && r>=end)return segtree[node];
    if(end<l || r<st)return 0;
    int mid=(st+end)/2;
    return query(node*2,st,mid,l,r)+query(node*2+1,mid+1,end,l,r);
}
ll querypath(int u,int v){
    ll res=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]])swap(u,v);
        int start=head[u];
        res+=query(1,1,curpos,pos[start],pos[u]);
        u=parent[start];
    }
    if(depth[u]>depth[v])swap(u,v);
    res+=query(1,1,curpos,pos[u],pos[v]);
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    ll n,q,u,v,type;
    cin>>n>>q;
    vector<ll>vc(n+1);
    for(ll i=1;i<=n;i++)cin>>vc[i];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[1]=-1;
    depth[1]=0;
    dfs(1);
    decompose(1,1);
    for(int i=1;i<=n;i++){
        basearray[pos[i]]=vc[i];
    }
    build(1,1,curpos);
    while(q--){
        cin>>type;
        if(type==1){
            int node,val;
            cin>>node>>val;
            update(1,1,curpos,pos[node],val);
        }
        else{
            cin>>v;
            cout<<querypath(1,v)<<endl;
        }
    }
    return 0;
}
