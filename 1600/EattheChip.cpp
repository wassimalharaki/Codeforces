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

void solve() {
    int h, w; cin >> h >> w;
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int xdiff = abs(xb - xa);
    if (xa >= xb) {
        cout << "DRAW" << nl;
        return;
    }
    if (xdiff & 1) {
        while (abs(xb - xa) != 0) {
            if (yb > ya)
                ya++;
            else if (yb < ya)
                ya--;
            xa++;

            if (xb == xa) {
                if (yb == ya) {
                    cout << "ALICE" << nl;
                    return;
                }
                else break;
            }

            if (yb > ya)
                yb += (yb == w ? 0 : 1);
            else if (yb < ya)
                yb += (yb == 1 ? 0 : -1);
            else {
                cout << "ALICE" << nl;
                return;
            }
            xb--;
        }
        cout << "DRAW" << nl;
    }
    else {
        while (abs(xb - xa) != 0) {
            if (ya > yb)
                ya += (ya == w ? 0 : 1);
            else if (ya < yb)
                ya += (ya == 1 ? 0 : -1);
            else {
                cout << "BOB" << nl;
                return;
            }
            xa++;

            if (ya > yb)
                yb++;
            else if (ya < yb)
                yb--;
            xb--;

            if (xb == xa) {
                if (yb == ya) {
                    cout << "BOB" << nl;
                    return;
                }
                else break;
            }
        }
        cout << "DRAW" << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}