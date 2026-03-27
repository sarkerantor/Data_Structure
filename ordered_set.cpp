#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    // k-th element
    cout << "0th index: " << *s.find_by_order(0) << endl;
    cout << "2nd index: " << *s.find_by_order(2) << endl;

    // less than x
    cout << "Elements < 25: " << s.order_of_key(21) << endl;

    // delete
    s.erase(20);

    // print all
    for(auto x : s) {
        cout << x << " ";
    }

    return 0;
}
