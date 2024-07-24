#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(k + 1), b(k + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    auto check = [&](int x) -> v<v<int>> {
        v<v<int>> ans;
        priority_queue<ai2, v<ai2>, greater<ai2>> sz;

        for (int i = 0; i < x; i++) {
            sz.push({0, (int) ans.size()});
            ans.push_back({});
        }

        for (int i = k; i; i--) {
            auto [m, j] = sz.top();
            int curr = a[i];
            while (curr and m < b[i]) {
                ans[j].push_back(i);
                curr--;
                sz.pop();
                sz.push({m + 1, j});
                tie(m, j) = tuple_cat(sz.top());
            }
            while (curr) {
                sz.push({1, (int) ans.size()});
                ans.push_back({i});
                curr--;
            }
        }

        return ans;
    };

    v<v<int>> ans;
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        auto ok = check(mid);

        if (ok.size() == mid)
            hi = mid - 1, ans.swap(ok);
        else
            lo = mid + 1;
    }

    cout << ans.size() << nl;
    for (auto& x : ans) {
        cout << x.size() << " ";
        for (int& y : x)
            cout << y << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}