#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct line {
    mutable int a, b, p;
    bool operator<(const line& o) const { return a < o.a; }
    bool operator<(int x) const { return p < x; }
    int operator()(int x) const { return a * x + b; }
};

// O(logn)
// dp[i] = max(a[j] * x[i] + b[j])
struct dynamic_cht : multiset<line, less<>> {
    static const int inf = LLONG_MAX;

    int div(int a, int b) {
        return a / b - ((a ^ b) < 0 && a % b); 
    }

    bool isect(iterator x, iterator y) {
        if (y == end())
            return x -> p = inf, 0;

        if (x -> a == y -> a)
            x -> p = x -> b > y -> b ? inf : -inf;
        else
            x -> p = div(y -> b - x -> b, x -> a - y -> a);
        return x -> p >= y -> p;
    }

    void add(int a, int b) {
        auto z = insert({a, b, 0}), y = z++, x = y;

        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));

        while ((y = x) != begin() && (--x) -> p >= y -> p)
            isect(x, erase(y));
    }

    int prod(int x) { return (*lower_bound(x))(x); }
};

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<int> dp(n);
    dynamic_cht cht; cht.add(- b[0], 0);
    for (int i = 1; i < n; i++) {
        dp[i] = - cht.prod(a[i]);
        cht.add(- b[i], - dp[i]);
    }
    cout << dp.back() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}