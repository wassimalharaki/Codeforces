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

void solve() {
    int n; cin >> n;

    v<array<int, 3>> a(n);
    for (auto& x : a) cin >> x[1];

    stack<int> mono;
    for (int i = n - 1; i >= 0; i--) {
        while (not mono.empty() and a[mono.top()][1] >= a[i][1])
            mono.pop();
        a[i][2] = (mono.empty() ? n : mono.top());
        mono.push(i);
    }
    mono = stack<int>();

    for (int i = 0; i < n; i++) {
        while (not mono.empty() and a[mono.top()][1] >= a[i][1])
            mono.pop();
        a[i][0] = (mono.empty() ? -1 : mono.top());
        mono.push(i);
    }

    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        if (x[1] == y[1])
            return x[2] - x[0] > y[2] - y[0];
        return x[1] > y[1];
    });

    v<int> ans(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int x = (a[i][2] - a[i][0] - 1);
        while (k < x)
            ans[k++] = a[i][1];
    }

    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}