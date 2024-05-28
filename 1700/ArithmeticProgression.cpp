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

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    if (n == 1) {
        cout << -1 << nl;
        return;
    }

    map<int, int> have;
    auto rem = [&](int x) {
        if (--have[x] == 0)
            have.erase(x);
    };
    auto add = [&](int x) {
        ++have[x];
    };

    for (int i = 1; i < n; i++)
        add(a[i] - a[i - 1]);
    
    set<int> ans;
    if (have.size() == 1) {
        ans.insert(a[0] - have.begin() -> first);
        ans.insert(a.back() + have.begin() -> first);
    }

    for (int i = 0; i < n - 1; i++) {
        int diff = a[i + 1] - a[i];
        if (diff & 1) continue;

        rem(diff);
        add(diff >> 1);
        if (have.size() == 1)
            ans.insert(a[i] + (diff >> 1));
        rem(diff >> 1);
        add(diff);
    }

    cout << ans.size() << nl;
    for (int a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}