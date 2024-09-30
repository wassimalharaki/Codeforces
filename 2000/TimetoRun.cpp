#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    if (k > 4 * n * m - 2 * (n + m)) {
        cout << "NO" << nl;
        return;
    }

    v<pair<int, string>> ans;
    if (m - 1)
        ans.push_back({m - 1, "R"});
    for (int i = 0; i < n - 1; i++) {
        ans.push_back({1, "D"});
        if (m - 1)
            ans.push_back({1, "L"});
        if (m - 2 > 0)
            ans.push_back({m - 2, "UDL"});
        if (m - 1)
            ans.push_back({m - 1, "R"});
    }
    if (n - 1)
        ans.push_back({n - 1, "U"});
    if (m - 1)
        ans.push_back({m - 1, "L"});
    if (n - 1)
        ans.push_back({n - 1, "D"});
    if (n - 1)
        ans.push_back({n - 1, "U"});

    int curr = 0;
    for (auto& [x, s] : ans)
        curr += x * s.size();
    
    while (curr > k) {
        auto [x, s] = ans.back();
        ans.pop_back();
        if (curr - x * (int) s.size() > k)
            curr -= x * s.size();
        else {
            int diff = curr - k;
            int y = (diff + (int) s.size() - 1) / s.size();
            x -= y;
            curr -= y * s.size();
            if (x) ans.push_back({x, s});
            if (curr < k)
                ans.push_back({1, s.substr(0, k - curr)});
            break;
        }
    }

    cout << "YES" << nl;
    cout << ans.size() << nl;
    for (auto& [x, s] : ans)
        cout << x << " " << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}