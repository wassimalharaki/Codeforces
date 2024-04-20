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

int INF = (1ll << 32) - 1;

bool can_add(int x, int y) {
    int diff = INF - x;
    return y <= diff;
}

bool can_mult(int x, int y) {
    if (x == 0) return 1;
    int lim = INF / x;
    return y <= lim;
}

void solve() {
    int l; cin >> l;
    
    auto open = [&](auto&& open) -> int {
        int n; cin >> n;
        int x = 0;
        while (l--) {
            string s; cin >> s;
            if (s == "add") {
                if (can_add(x, 1))
                    x++;
                else {
                    cout << "OVERFLOW!!!";
                    exit(0);
                }
            }
            else if (s == "for") {
                int y = open(open);
                if (can_add(x, y))
                    x += y;
                else {
                    cout << "OVERFLOW!!!";
                    exit(0);
                }
            }
            else {
                if (can_mult(x, n))
                    return x * n;
                else {
                    cout << "OVERFLOW!!!";
                    exit(0);
                }
            }
        }
    };

    int x = 0;
    while (l--) {
        string s; cin >> s;
        if (s == "add") {
            if (can_add(x, 1))
                x++;
            else {
                cout << "OVERFLOW!!!";
                return;
            }
        }
        else {
            int y = open(open);
            if (can_add(x, y))
                x += y;
            else {
                cout << "OVERFLOW!!!";
                return;
            }
        }
    }
    cout << x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}