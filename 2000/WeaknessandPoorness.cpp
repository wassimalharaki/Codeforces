#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const double eps = 5e-12;

double get(v<int>& a, double x) {
    double min = 0, max = 0, ans = 0, curr = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        curr += a[i] - x;
        min = std::min(min, curr);
        max = std::max(max, curr);
        ans = std::max({
            ans,
            abs(curr - min),
            abs(curr - max)
        });
    }
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    double lo = -1e4, hi = 1e4;
    while (hi - lo > eps) {
        double l = lo + (hi - lo) / 3;
        double r = hi - (hi - lo) / 3;
        if (get(a, l) > get(a, r))
            lo = l;
        else
            hi = r;
    }
    cout << fixed << setprecision(15) << get(a, lo) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}