#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class Fenwick{
public:
    int n;
    vector<ll>bit;
    Fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }
    void update(int i,ll val){
        while(i<=n){
            bit[i]+=val;
            i+=(i&(-i));
        }
    }
    ll query(int i){
        ll sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i&(-i));
        }
        return sum;
    }
    ll rangequery(int l,int r){
        return query(r)-query(l-1);
    }
};
int main(){
    int n;
    cin>>n;
    Fenwick ft(n);
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ft.update(i,arr[i]);
    }
    cout<<ft.query(5)<<"\n";
    cout<<ft.rangequery(3,7)<<"\n";
    return 0;
}
