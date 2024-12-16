#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = accumulate(a.begin(), a.end(), 0ll);
    v<int> in(n);
    v<set<array<int, 2>>> out(n);
    
    int q; cin >> q;
    while (q--) {
        int s, t, u; cin >> s >> t >> u;
        auto it = out[--s].lower_bound({t, -1});
        if (it != out[s].end() and (*it)[0] == t) {
            if (--in[(*it)[1]] < a[(*it)[1]])
                ans++;
            out[s].erase(it);
        }
        if (u) {
            out[s].insert({t, --u});
            if (++in[u] <= a[u])
                ans--;
        }
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}