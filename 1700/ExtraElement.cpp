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

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());

    map<int, int> cnt;
    for (int i = 1; i < n; i++)
        cnt[a[i][0] - a[i - 1][0]]++;
    
    auto rem = [&](int x) {
        if (--cnt[x] == 0)
            cnt.erase(x);
    };

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            int x = a[i + 1][0] - a[i][0];
            rem(x);
            if (cnt.size() <= 1) {
                cout << a[i][1] << nl;
                return;
            }
            cnt[x]++;
        }
        else if (i == n - 1) {
            int x = a[i][0] - a[i - 1][0];
            rem(x);
            if (cnt.size() <= 1) {
                cout << a[i][1] << nl;
                return;
            }
            cnt[x]++;
        }
        else {
            int x = a[i][0] - a[i - 1][0];
            int y = a[i + 1][0] - a[i][0];
            int z = a[i + 1][0] - a[i - 1][0];
            rem(x); rem(y);
            cnt[z]++;
            if (cnt.size() <= 1) {
                cout << a[i][1] << nl;
                return;
            }
            rem(z);
            cnt[x]++; cnt[y]++;
        }
    }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}