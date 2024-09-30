#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto get = [&](int x, int y) -> int {
        if (x < y) swap(x, y);
        if ((x + 1) / 2 <= x - y)
            return (x + 1) / 2;

        int k = x - y;
        x -= 2 * k; y -= k;

        k += x / 3 * 2;
        x %= 3; y %= 3;

        if (x == 2) k += 2;
        else if (x == 1) k++;
        return k;
    };

    int ans = 0;
    {
        auto b = a;
        sort(b.begin(), b.end());
        ans = (b[0] + 1) / 2 + (b[1] + 1) / 2;
    }

    for (int i = 0; i < n - 1; i++)
        ans = min(ans, get(a[i], a[i + 1]));
    for (int i = 0; i < n - 2; i++) {
        int x = max(a[i], a[i + 2]);
        int y = min(a[i], a[i + 2]);
        ans = min(ans, y + (x - y + 1) / 2);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}