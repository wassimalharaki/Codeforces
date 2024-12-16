#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int x, y, a, b;
    cin >> a >> b >> x >> y;
    if (x < y) swap(x, y);
    if (a < b) swap(a, b);

    int ans = 0;
    {
        int c = (x - y ? (a - b) / (x - y) : LLONG_MAX);
        c = min({c, a / x, b / y});
        a -= c * x, b -= c * y;
        ans += c;
    }

    {
        int c = b / (x + y);
        a -= c * (x + y);
        b -= c * (x + y);
        ans += 2 * c + (a >= x and b >= y);
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