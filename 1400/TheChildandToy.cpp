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

struct Part {
    int sum = 0;
    vi edges;
};

void solve() {
    int n, m; cin >> n >> m;

    vpii nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].F;
        nums[i].S = i + 1;
    }

    v<Part> p(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        p[a].edges.pb(b);
        p[a].sum += nums[b - 1].F;
        p[b].edges.pb(a);
        p[b].sum += nums[a - 1].F;
    }

    sort(rall(nums));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p[nums[i].S].sum;
        for (int& u : p[nums[i].S].edges)
            p[u].sum -= nums[i].F;
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}