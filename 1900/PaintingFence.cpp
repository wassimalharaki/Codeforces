#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto go = [](v<int> a, auto&& go) -> int {
        v<v<int>> blocks;
        int m = a.size();
        int mn = *min_element(a.begin(), a.end());

        if (a[0] != mn)
            blocks.push_back({{a[0] - mn}});

        for (int i = 1; i < m; i++)
            if (a[i] != mn and a[i - 1] == mn)
                blocks.push_back({{a[i] - mn}});
            else if (a[i] != mn and a[i - 1] != mn)
                blocks.back().push_back(a[i] - mn);

        int ans = mn;
        for (auto& x : blocks)
            ans += go(x, go);
        return min(m, ans);
    };
    cout << go(a, go) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}