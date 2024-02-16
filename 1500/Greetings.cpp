#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F >> nums[i].S;
    sort(all(nums), [](pii& p, pii& q) {
        if (p.F == q.F)
            return p.S > q.S;
        return p.F < q.F; 
    });
 
    ordered_set<pii> right;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        right.insert({nums[i].S, -1 * i});
        ans += right.size() - right.order_of_key({nums[i].S, -1 * i}) - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}