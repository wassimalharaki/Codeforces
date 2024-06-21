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

int ask_or(int i, int j) {
    cout << "or " << i << " " << j << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

int ask_and(int i, int j) {
    cout << "and " << i << " " << j << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(int x) {
    cout << "finish " << x << endl;
    exit(0);
}

void solve() {
    int n, k; cin >> n >> k;

    v<array<int, 2>> q(n + 1);
    q[1] = {ask_or(2, 3), ask_and(2, 3)};
    for (int i = 2; i <= n; i++)
        q[i][0] = ask_or(1, i),
        q[i][1] = ask_and(1, i);
    
    int x = INT_MAX;
    for (int i = 2; i <= n; i++)
        x &= q[i][0];

    v<int> ans(n);
    for (int i = 1; i < (1 << 30); i <<= 1)
        if ((x & i) and ((q[2][1] & i) or (q[1][1] & i) == 0))
            ans[0] += i;

    for (int i = 2; i <= n; i++) 
        for (int j = 1; j < (1 << 30); j <<= 1)
            if ((q[i][0] & j) and ((ans[0] & j) == 0 or (q[i][1] & j)))
                ans[i - 1] += j;
    sort(ans.begin(), ans.end());
    answer(ans[k - 1]);
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}