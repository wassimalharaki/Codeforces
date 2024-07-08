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

// O(n), O(log(n))
template <class T>
struct BIT {
    int n;
    vector<T> d;

    BIT(int _n) {
        n = _n;
        d.resize(_n);
    }

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += d[r - 1];
            r -= r & -r;
        }
        return s;
    }

    void add(int p, T x) {
        p++;
        while (p <= n) {
            d[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    v<int> b(a);
    sort(b.begin(), b.end());
    
    for (int& x : a)
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    
    int ans = 0;
    BIT<int> one(n), two(n);
    for (int& x : a) {
        ans += two.sum(x, n);
        two.add(x, one.sum(x, n));
        one.add(x, 1);
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