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

const int N = 20;

void solve() {
    int n; cin >> n;

    v<int> bits(20);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < N; j++)
            if ((1 << j) & x)
                bits[j]++;
    }

    v<int> a(*max_element(bits.begin(), bits.end()) + 1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < bits[i]; j++)
            a[j] += 1 << i;

    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += a[i] * a[i];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}