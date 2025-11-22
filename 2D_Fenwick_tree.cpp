#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class Fenwick2d{
public:
    int n,m;
    vector<vector<ll>>bit;
    Fenwick2d(int n,int m){
        this->n=n;
        this->m=m;
        bit.assign(n+1,vector<ll>(m+1,0));
    }
    void update(int x,int y,ll val){
        for(int i=x;i<=n;i+=(i&(-i))){
            for(int j=y;j<=m;j+=(j&(-j))){
                bit[i][j]+=val;
            }
        }
    }
    ll sum(int x,int y){
        ll sum=0;
        for(int i=x;i>0;i-=(i&(-i))){
            for(int j=y;j>0;j-=(j&(-j))){
                sum+=bit[i][j];
            }
        }
        return sum;
    }
    ll query(int x1,int y1,int x2,int y2){
        return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
    }
};
int main(){
    int n=5,m=5;
    Fenwick2d ft(n,m);
    ft.update(2,3,5);
    ft.update(4,2,7);
    cout<<ft.query(1,1,5,5)<<endl;
    cout<<ft.query(2,3,5,5)<<endl;
    cout<<ft.query(1,4,5,5)<<endl;
    return 0;
}
