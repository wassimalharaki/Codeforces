#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x].push_back(i);
    }

    int ans = n;
    for (auto& b : a) {
        int ends = 1;
        for (int i = 1; i < (int) b.size(); i++) {
            int diff = b[i] - b[i - 1] - 1;
            if (diff == 1)
                ends = min(ends - 1, 1ll);
            else if (diff > 1)
                ends = 0;
            ends++;
            if (ends > 2) ans--;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}