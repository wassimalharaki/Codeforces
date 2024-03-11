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

bool bruteforce(v<pair<int, int>>& nums) {
    int n = nums.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if ((1 << i) & mask)
                x += nums[i].first;
            else
                y += nums[i].second;
        if (abs(x - y) <= 500) return 1;
    }
    return 0;
}

void solve() {
    int n; cin >> n;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        int diff1 = abs(x + l - y);
        int diff2 = abs(y + r - x);
        if (diff1 < diff2) {
            x += l;
            cout << 'A';
        }
        else {
            y += r;
            cout << 'G';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}