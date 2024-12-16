#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define nl '\n'
#define v vector

template<typename T>
using indexed_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    sort(a.begin(), a.end(), [&](auto& x, auto& y) {
        if (x[1] == y[1])
            return x[0] < y[0];
        return x[1] < y[1];
    });
    
    indexed_set<pair<int, int>> up, down;
    int ans = 0, x0 = 0, y0 = 0;
    for (int i = 0; i < n; i++)
        up.insert({a[i][0], i});

    auto check = [&](int k) -> pair<bool, int> {
        if (up.size() < 2 * k) return {0, 0};
        if (down.size() < 2 * k) return {0, 0};
        {
            int x = (*up.find_by_order(k - 1)).first + 1;
            int lft = up.order_of_key({x, -1});

            int i = down.order_of_key({x, -1});
            int sz = (int) down.size() - i;
            if (sz >= k and (int) down.size() - sz >= k and (int) up.size() - lft >= k)
                return {1, x};
        }
        {
            int x = (*down.find_by_order(k - 1)).first + 1;
            int lft = down.order_of_key({x, -1});

            int i = up.order_of_key({x, -1});
            int sz = (int) up.size() - i;
            if (sz >= k and (int) up.size() - sz >= k and (int) down.size() - lft >= k)
                return {1, x};
        }
        return {0, 0};
    };

    set<int> cand;
    for (auto& [x, y] : a)
        cand.insert(y);

    int j = 0;
    for (int y : cand) {
        while (j < n and a[j][1] < y) {
            up.erase({a[j][0], j});
            down.insert({a[j][0], j});
            j++;
        }
        {
            int lo = 1, hi = n / 4;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                auto [ok, x] = check(mid);
                if (ok) {
                    if (mid > ans)
                        ans = mid, x0 = x, y0 = y;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
        }
    }
    cout << ans << nl << x0 << " " << y0 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}