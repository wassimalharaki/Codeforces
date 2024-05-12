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

int calc(int x, int y, int z) {
    return (x - y) * (x - y)
         + (x - z) * (x - z)
         + (y - z) * (y - z);
}

void solve() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;

    v<int> a(n1), b(n2), c(n3);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    auto fix = [](v<int>& d, int mid) -> int {
        auto it = lower_bound(d.begin(), d.end(), mid);
        if (it == d.end())
            return *(--it);
        else if (it == d.begin())
            return *it;
        else {
            int a = *it;
            int b = *(--it);
            return a - mid > mid - b ? b : a;
        }
    };

    auto get = [&fix](v<int>& a, v<int>& b, v<int>& c) -> int {
        int curr = LLONG_MAX;
        for (int& x : a) {
            int y, z;
            auto it1 = lower_bound(b.begin(), b.end(), x);
            auto it2 = lower_bound(c.begin(), c.end(), x);
            if (it1 == b.end() or it2 == c.end()) continue;
            y = *it1;
            z = *it2;
            if (y > z)
                z = fix(c, (x + y) / 2);
            else if (z > y)
                y = fix(b, (x + z) / 2);
            curr = min(curr, calc(x, y, z));
        }
        return curr;
    };
    cout << min({get(a, b, c), get(b, a, c), get(c, a, b)}) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}