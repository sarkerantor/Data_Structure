#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class Segtree{
private:
    int n;
    vector<ll>tree;
public:
    Segtree(int n){
        this->n=n;
        tree.assign(2*n,0);
    }
    void build(vector<ll>&arr){
        for(int i=0;i<n;i++){
            tree[i+n]=arr[i];
        }
        for(int i=n-1;i>=0;i--){
            tree[i]=tree[i<<1] + tree[i<<1|1];
        }
    }
    void update(int pos,ll val){
        pos+=n;
        tree[pos]=val;
        while(pos>1){
            pos>>=1;
            tree[pos]=tree[pos<<1]+tree[pos<<1|1];
        }
    }
    ll query(int l,int r){
        l+=n;
        r+=n;
        ll ans=0;
        while(l<r){
            if(l&1)ans+=tree[l++];
            if(r&1)ans+=tree[--r];
            l>>=1;
            r>>=1;
        }
        return ans;
    }
};
int main(){
    int n=8;
    vector<ll>arr={1,3,5,7,9,11,2,4};
    Segtree st(n);
    st.build(arr);
    cout<<st.query(0,4)<<endl;
    st.update(2,10);
    cout<<st.query(0,4)<<endl;
    return 0;
}
