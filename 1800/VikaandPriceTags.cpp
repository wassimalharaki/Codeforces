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

int bf(int a, int b) {
    if (a == 0) return 0;
    return a < b ? 1 + bf(b, b - a) : 1 + bf(b, a - b);
}

int get(int a, int b) {
    if (a == 0)
        return 0;
    else if (b == 0)
        return 1;
    else if (a <= 20 and b <= 20)
        return bf(a, b);
    else if (a < b)
        return 1 + get(b, b - a);
    else if (b > abs(a - b))
        return 1 + get(b, a - b);
    else {
        int x = a / (2 * b);
        return x * 3 + get(a - x * 2 * b, b);
    }
}

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    array<int, 3> rem{0, 0, 0};
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 and b[i] == 0)
            continue;
        rem[get(a[i], b[i]) % 3]++;
    }
    int x = 0;
    for (int i = 0; i < 3; i++)
        x += rem[i] > 0;
    cout << (x <= 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}