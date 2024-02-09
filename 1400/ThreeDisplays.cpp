#include <bits/stdc++.h>

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

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

struct Node {
    int min = INF;
    vi adj;
};

void solve() {
    int n; cin >> n;
    
    vi nums(n), cost(n);
    for (int& a : nums) cin >> a;
    for (int& a : cost) cin >> a;

    v<Node> nodes(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] < nums[j]) {
                nodes[i].adj.pb(j);
                nodes[i].min = min(nodes[i].min, cost[j]);
            }
    
    int ans = INF;
    for (int i = 0; i < n; i++)
        for (int& j : nodes[i].adj)
            if (nodes[j].min != INF)
                ans = min(ans, cost[i] + cost[j] + nodes[j].min);
    cout << (ans == INF ? -1 : ans) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}