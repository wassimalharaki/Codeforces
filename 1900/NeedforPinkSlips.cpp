#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
// #define v vector

const long double eps = 1e-9;

void solve() {
    long double ans = 0;
    auto go = [&](int i, double c, double m, double p, double curr, double v, auto&& go) -> void {
        ans += i * p * curr;

        bool cz = abs(c) < eps;
        bool mz = abs(m) < eps;

        if (cz and mz);
        else if (cz)
            go(i + 1, c, max(0., m - v), p + min(m, v), curr * m, v, go);
        else if (mz)
            go(i + 1, max(0., c - v), m, p + min(c, v), curr * c, v, go);
        else {
            go(i + 1, max(0., c - v), m + min(c, v) / 2., p + min(c, v) / 2., curr * c, v, go);
            go(i + 1, c + min(m, v) / 2., max(0., m - v), p + min(m, v) / 2., curr * m, v, go);
        }
    };

    double c, m, p, v;
    cin >> c >> m >> p >> v;
    go(1, c, m, p, 1., v, go);
    cout << fixed << setprecision(12) << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}