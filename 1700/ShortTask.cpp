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

const int N = 1e7 + 1;
int sum[N], best[N];

void solve() {
    int c; cin >> c;
    cout << (best[c] ? best[c] : -1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            sum[j] += i;

    memset(best, 0, sizeof(best));
    for (int i = 1; i < N; i++)
        if (sum[i] < N and best[sum[i]] == 0)
            best[sum[i]] = i;

    int T = 1;
    cin >> T;
    while (T--) solve();
}