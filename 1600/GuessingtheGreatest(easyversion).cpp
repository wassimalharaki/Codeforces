#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int pos; cin >> pos;
    return pos;
}

void solve() {
    int n; cin >> n;

    int x = ask(1, n);
    if (x == 1) {
        int l = x + 1, r = n, ans = l;
        while (l <= r) {
            int mid = (l + r) / 2;
            int y = ask(x, mid);

            if (y == x)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << "! " << ans << endl;
    }
    else if (x == n) {
        int l = 1, r = x - 1, ans = l;
        while (l <= r) {
            int mid = (l + r) / 2;
            int y = ask(mid, x);

            if (y == x)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << "! " << ans << endl;
    }
    else {
        if (ask(1, x) == x) {
            int l = 1, r = x - 1, ans = l;
            while (l <= r) {
                int mid = (l + r) / 2;
                int y = ask(mid, x);

                if (y == x)
                    ans = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            cout << "! " << ans << endl;
        }
        else {
            int l = x + 1, r = n, ans = l;
            while (l <= r) {
                int mid = (l + r) / 2;
                int y = ask(x, mid);

                if (y == x)
                    ans = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            cout << "! " << ans << endl;
        }
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}