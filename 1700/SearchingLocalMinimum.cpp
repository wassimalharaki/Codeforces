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

int n;
v<int> a;

int get(int i) {
    if (i < 1 or i > n)
        return INT_MAX;
    return a[i];
}

void ask(int i) {
    if (i < 1 or i > n or a[i] != -1) return;
    cout << "? " << i << endl;
    int x; cin >> x;
    a[i] = x;
}

bool works(int i) {
    for (int j = i - 1; j <= i + 1; j++)
        ask(j);
    return get(i) < get(i - 1) and get(i) < get(i + 1);
}

void solve() {
    cin >> n;
    a.resize(n + 1, -1);

    if (works(1)) {
        cout << "! 1" << endl;
        return;
    }

    if (works(n)) {
        cout << "! " << n << endl;
        return;
    }

    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (works(mid)) {
            cout << "! " << mid << endl;
            break;
        }

        if (get(mid - 1) < get(mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}