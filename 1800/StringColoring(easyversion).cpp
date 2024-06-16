#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = {c, i};
    }

    v<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto it = min_element(a.begin() + i, a.end());
        int k = it - a.begin();

        set<int> ok;
        for (int j = i; j < k; j++)
            ok.insert(ans[a[j][1]]);
        ok.erase(0);

        if (ok.size() == 2 or (ok.size() and *ok.begin() == ans[a[k][1]])) {
            cout << "NO";
            return;
        }

        int x = (ok.size() ? *ok.begin() : (ans[a[k][1]] == 1 ? 2 : 1));
        int y = (x == 1 ? 2 : 1);

        for (int j = i; j < k; j++)
            ans[a[j][1]] = x;
        ans[a[k][1]] = y;

        for (int j = k - 1; j >= i; j--)
            swap(a[j], a[j + 1]);
    }

    cout << "YES" << nl;
    for (int& x : ans)
        cout << x - 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}