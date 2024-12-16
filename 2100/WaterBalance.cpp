#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    #define f first
    #define s second

    v<pair<double, int>> a;
    for (int i = 0; i < n; i++) {
        int z; cin >> z;
        pair<double, int> x{z, 1};
        while (a.size() and a.back().f >= x.f) {
            auto y = a.back(); a.pop_back();
            x.f = (x.f * x.s + y.f * y.s) / (x.s + y.s);
            x.s += y.s;
        }
        a.push_back(x);
    }

    cout << fixed << setprecision(9);
    for (auto& x : a)
        while (x.s--)
            cout << x.f << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}