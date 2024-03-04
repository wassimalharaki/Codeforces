#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

using pii = pair<int, int>;

void solve() {
    int n, k; cin >> n >> k;

    v<array<int, 2>> ac(k);
    for (int i = 0; i < k; i++)
        cin >> ac[i][0];
    for (int i = 0; i < k; i++)
        cin >> ac[i][1];
    sort(all(ac));

    v<int> pos(k), temp(k);
    for (int i = 0; i < k; i++)
        pos[i] = ac[i][0], temp[i] = ac[i][1];
    
    int add = 0, sub = 1, left = 1e18;
    priority_queue<pii, v<pii>, greater<pii>> right;
    right.push({1e18, k});

    for (int i = 0; i < k; i++)
        right.push({pos[i] + temp[i], i});

    v<int> ok(k + 1);
    for (int i = 1; i <= n; i++) {
        int l = left + add, r = right.top().first - sub;
        cout << min(l, r) << " ";
        sub++; add++;
        if (not binary_search(all(pos), i)) continue;
        int j = lower_bound(all(pos), i) - pos.begin();
        ok[j] = 1;
        while (ok[right.top().second])
            right.pop();
        if (temp[j] + 1 < left + add)
            add = 1, left = temp[j];
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}