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
    int n, q; cin >> n >> q;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> prefix(n + 1);
    map<int, v<int>> have;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ nums[i];
        have[prefix[i + 1]].push_back(i);
    }

    while (q--) {
        int l, r; cin >> l >> r;

        int x = prefix[r] ^ prefix[l - 1];
        if (x == 0)
            cout << "YES" << nl;
        else {
            int look = x ^ prefix[l - 1];
            auto& a = have[look];
            auto it = lower_bound(a.begin(), a.end(), l - 1);
            if (it == a.end() or *it >= r)
                cout << "NO" << nl;
            else {
                auto& b = have[look ^ x];
                auto it2 = lower_bound(b.begin(), b.end(), *it + 1);
                if (it2 == b.end() or *it2 >= r - 1)
                    cout << "NO" << nl;
                else
                    cout << "YES" << nl;
            }
        }
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}