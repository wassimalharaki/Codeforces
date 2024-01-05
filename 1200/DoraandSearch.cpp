#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    ordered_set<int> check;
    for (int i = 1; i <= n; i++)
        check.insert(i);
    
    int i = 0, j = n - 1;
    while (i <= j) {
        bool ok = 1;
        int posi = check.order_of_key(nums[i]);
        if (posi == 0 or posi == check.size() - 1)
            check.erase(nums[i]), i++, ok = 0;

        int posj = check.order_of_key(nums[j]);
        if (posj == 0 or posj == check.size() - 1)
            check.erase(nums[j]), j--, ok = 0;
        
        if (ok) {
            cout << i + 1 << " " << j + 1 nl;
            return;
        }
    }
    cout << -1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}