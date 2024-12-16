#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 1e4 + 1;

void solve() {
    int n, m; cin >> m >> n;

    v a(m, bitset<N>());
    for (auto& x : a) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            int y; cin >> y; x[y] = 1;
        }
    }
    bool ans = 1;
    for (int i = 0; i < m; i++) {
        bool ok = 1;
        for (int j = i - 1; j >= 0; j--)
            ok &= (a[i] & a[j]).count() > 0;
        ans &= ok;
    }
    cout << (ans ? "possible" : "impossible") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}