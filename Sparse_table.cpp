#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt","r",stdin);
    int n=9;
    int arr[]={1,-2,4,3,-5,6,3,-82,-22};
    int maxk=__lg(n);
    int st[maxk+1][n];
    for(int i=0;i<n;i++)st[0][i]=arr[i];
    for(int i=1;i<=maxk;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    while(true){
        int l,r;
        cin>>l>>r;
        int k=__lg(r-l+1);
        cout<<min(st[k][l],st[k][r-(1<<k)+1])<<endl;
    }
    return 0;
}
