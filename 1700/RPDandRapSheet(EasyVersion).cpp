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

int ask(int x) {
    cout << x << endl;
    int r; cin >> r;
    return r;
}

void solve() {
    int n, k; cin >> n >> k;

    if (ask(0)) return;
    for (int i = 1; i < n; i++) {
        int r = ask(i ^ (i - 1));
        if (r == 1) return;
    }
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}