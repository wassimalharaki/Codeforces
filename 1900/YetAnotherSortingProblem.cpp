#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void shift_left(int& a, int& b, int& c) {
    tie(a, b, c) = make_tuple(b, c, a);
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    v<int> b(a);
    sort(b.begin(), b.end());

    if (n <= 2) {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << nl;
        return;
    }

    if (set<int>(a.begin(), a.end()).size() != n) {
        cout << "YES" << nl;
        return;
    }

    v<set<int>> pos(n + 1);
    for (int i = 0; i < n; i++)
        pos[a[i]].insert(i);

    for (int i = 0; i < n - 2; i++) {
        if (a[i] == b[i]) {
            pos[a[i]].erase(i);
            continue;
        }
        int x = *pos[b[i]].begin();

        if (x == n - 1) {
            pos[a[n - 1]].erase(n - 1);
            pos[a[n - 2]].erase(n - 2);
            pos[a[i]].erase(i);

            pos[a[i]].insert(n - 2);
            pos[a[n - 2]].insert(n - 1);

            shift_left(a[i], a[n - 2], a[n - 1]);
            shift_left(a[i], a[n - 2], a[n - 1]);
        }
        else {
            pos[a[x]].erase(x);
            pos[a[i]].erase(i);
            pos[a[n - 1]].erase(n - 1);
            
            pos[a[i]].insert(n - 1);
            pos[a[n - 1]].insert(x);

            shift_left(a[i], a[x], a[n - 1]);
        }
    }

    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}