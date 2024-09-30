#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, q; cin >> n >> q;
    int B = sqrt(n) * 0.9;

    v<int> a(n), cnt(n + 1);
    for (int& x : a)
        cin >> x, cnt[x]++;
    
    map<int, v<int>> pref;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] < B) continue;
        pref[i].resize(n + 1);
        auto& x = pref[i];
        for (int j = 0; j < n; j++)
            x[j + 1] = x[j] + (a[j] == i);
    }

    fill(cnt.begin(), cnt.end(), 0);
    while (q--) {
        int l, r; cin >> l >> r;
        int sz = r - --l, freq = 0;
        if (sz < 2 * B) {
            for (int i = l; i < r; i++)
                freq = max(freq, ++cnt[a[i]]);
            for (int i = l; i < r; i++)
                --cnt[a[i]];
        }
        else {
            for (auto& [x, b] : pref)
                freq = max(freq, b[r] - b[l]);
        }
        cout << 1 + max(0, 2 * freq - sz - 1) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}