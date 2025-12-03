// Distinct Count
#include<bits/stdc++.h>
using namespace std;
    struct Query {
    int L, R, idx;
};

int block;

bool cmp(Query a, Query b) {
    if (a.L / block != b.L / block)
        return a.L < b.L;
    return a.R < b.R;
}


int main() {
    int n, q;
    cin >> n >> q;

    block = sqrt(n);

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].L >> queries[i].R;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), cmp);

    vector<int> ans(q);
    int cnt[1000001] = {0};
    int currentL = 0, currentR = -1;
    int distinct = 0;

    for(auto qr : queries){
        int L = qr.L;
        int R = qr.R;

        while(currentR < R){
            currentR++;
            if(++cnt[arr[currentR]] == 1) distinct++;
        }
        while(currentR > R){
            if(--cnt[arr[currentR]] == 0) distinct--;
            currentR--;
        }

        while(currentL < L){
            if(--cnt[arr[currentL]] == 0) distinct--;
            currentL++;
        }
        while(currentL > L){
            currentL--;
            if(++cnt[arr[currentL]] == 1) distinct++;
        }

        ans[qr.idx] = distinct;
    }

    for(int i=0;i<q;i++) cout<<ans[i]<<"\n";

    return 0;
}
