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

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int a = ask(1e9 - 1, 1e9);

    if (a == -1) {
        int lo = 2, hi = 1e9, ans = 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (ask(mid - 1, mid) == -1)
                hi = mid - 1;
            else
                lo = mid + 1, ans = mid;
        }
        cout << "! " << ans << endl;
    }
    else {
        int ans;
        for (int i = 1; i <= 49; i += 2) {
            int x = ask(i, i + 1), y = ask(i + 1, i);
            ans = x + y;
            if (x != y) break;
        }
        cout << "! " << ans << endl;
    }
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}