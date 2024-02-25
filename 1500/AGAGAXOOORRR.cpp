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

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int find = 0;
    for (int i = 0; i < n; i++) {
        find ^= nums[i];
        int curr = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            curr ^= nums[j];
            if (curr == find) {
                curr = 0;
                cnt++;
            }
        }
        if (curr == 0 and cnt > 1) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}