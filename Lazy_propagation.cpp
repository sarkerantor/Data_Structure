#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mx=100001;

struct Node{
    ll sum=0, prop=0;
} tree[mx*4];

int arr[mx];

void build(int node,int st,int en){
    if(st==en){
        tree[node].sum = arr[st];
        tree[node].prop = 0;
        return;
    }
    int mid = (st+en)/2;
    build(node*2,st,mid);
    build(node*2+1,mid+1,en);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
}

void update(int node,int st,int en,int l,int r,int val){
    if(r < st || l > en) return;
    if(l <= st && en <= r){
        tree[node].sum += (en-st+1)*val;
        tree[node].prop += val;
        return;
    }
    int mid = (st+en)/2;
    update(node*2,st,mid,l,r,val);
    update(node*2+1,mid+1,en,l,r,val);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum + tree[node].prop*(en-st+1);
}

ll query(int node,int st,int en,int l,int r,ll carry=0){
    if(r < st || l > en) return 0;
    if(l <= st && en <= r){
        return tree[node].sum + carry*(en-st+1);
    }
    int mid = (st+en)/2;
    ll q1 = query(node*2,st,mid,l,r,carry+tree[node].prop);
    ll q2 = query(node*2+1,mid+1,en,l,r,carry+tree[node].prop);
    return q1+q2;
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int type,l,r,val;
        cin>>type;
        if(type==1){ // update
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else{ // query
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}
