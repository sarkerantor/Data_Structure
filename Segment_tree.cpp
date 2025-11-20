#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx*4];
void build(int node,int st,int end){
    if(st==end)tree[node]=arr[st];
    else{
        int mid=st+(end-st)/2;
        int l=node*2;
        int r=node*2+1;
        build(l,st,mid);
        build(r,mid+1,end);
        tree[node]=tree[l]+tree[r];
    }
}
int query(int node,int st,int end,int l,int r){
    if(r<st||l>end)return 0;
    if(l<=st&&r>=end)return tree[node];
    int mid=st+(end-st)/2;
    int left=query(node*2,st,mid,l,r);
    int right=query(node*2+1,mid+1,end,l,r);
    return left+right;
}
void update(int node,int st,int end,int idx,int val){
    if(idx<st||idx>end)return;
    if(st==end){
        tree[node]=val;
        return;
    }
    int mid=st+(end-st)/2;
    update(node*2,st,mid,idx,val);
    update(node*2+1,mid+1,end,idx,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    return 0;
}
