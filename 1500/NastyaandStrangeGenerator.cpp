#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> nums(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        --nums[i];
        pos[nums[i]] = i;
    }

    int r = n - 1, x = 0;
    auto check = [&](auto&& check) -> bool {
        if (r <= 0) return 1;
        int j = pos[x];
        for (int i = j; i <= r; i++)
            if (nums[i] != x++) return 0;
        r = j - 1;
        return check(check);
    };
    cout << (check(check) ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}