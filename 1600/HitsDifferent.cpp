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

int get(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int left(int row) {
    return row * (row - 1) / 2 + 1;
}

int right(int row) {
    return row * (row + 1) / 2;
}

void solve() {
    int n; cin >> n;

    int lo = 1, hi = 2023, row;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int r = right(mid), l = left(mid);

        if (n >= l and n <= r) {
            row = mid;
            break;
        }
        else if (n < r)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    int l = n, r = n, ans = get(l, r);
    while (row) {
        l -= row; r -= --row;
        l = max(l, left(row));
        r = min(r, right(row));
        ans += get(l, r);
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