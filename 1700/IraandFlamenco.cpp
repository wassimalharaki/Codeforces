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

int mod = 1e9 + 7;

// O(log(min(a, b)))
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

// O(log(min(a, b)))
int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, m; cin >> n >> m;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    if (cnt.size() < m) {
        cout << 0 << nl;
        return;
    }

    if (m == 1) {
        cout << n << nl;
        return;
    }

    v<array<int, 2>> a;
    for (auto& [key, val] : cnt)
        a.push_back({key, val});

    multiset<int> gap;
    int curr = a[0][1];
    for (int i = 1; i < m; i++) {
        gap.insert(a[i][0] - a[i - 1][0]);
        curr = curr * a[i][1] % mod;
    }

    int ans = 0;
    if (*gap.rbegin() == 1)
        ans += curr;

    for (int i = m; i < a.size(); i++) {
        curr = curr * modinv(a[i - m][1]) % mod;
        curr = curr * a[i][1] % mod;
        gap.erase(gap.find(a[i - m + 1][0] - a[i - m][0]));
        gap.insert(a[i][0] - a[i - 1][0]);
        if (*gap.rbegin() == 1)
            add(ans, curr);
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