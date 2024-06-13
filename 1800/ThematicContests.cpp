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

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    v<int> cnt;
    for (auto& [key, val] : freq)
        cnt.push_back(val);
    sort(cnt.begin(), cnt.end());

    int ans = 0;
    for (int i = 1; i <= 2e5; i++) {
        auto it = lower_bound(cnt.begin(), cnt.end(), i);
        if (it == cnt.end()) break;
        
        int curr = i, j = 2 * i;
        while (1) {
            auto next = lower_bound(it + 1, cnt.end(), j);
            if (next == cnt.end()) break;
            it = next;
            curr += j;
            j <<= 1;
        }
        ans = max(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}