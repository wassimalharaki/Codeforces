#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    map<int, int> stops;
    v<array<int, 2>> a(n);
    for (auto& [d, x] : a) {
        cin >> d >> x;
        stops[d] = x;
        stops[d + k] = 0;
    }

    int prev = -1, ans = 0;
    stack<array<int, 2>> st;
    for (auto& [d, x] : stops) {
        if (prev == -1) {
            prev = d;
            st.push({d, x});
            continue;
        }
        int passed = d - prev;
        int need = passed * m;
        prev = d;
        int have = 0;
        while (st.size() and have < need) {
            if (st.top()[0] + k < d) {
                st.pop();
                continue;
            }
            int sub = min(st.top()[1], need - have);
            have += sub;
            st.top()[1] -= sub;
            if (st.top()[1] == 0) st.pop();
        }
        ans += have / m;
        if (x) st.push({d, x});
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}