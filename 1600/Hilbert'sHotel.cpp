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
    for (int& a : nums) {
        cin >> a;
        a = (a % n + n) % n;
    }

    map<int, int> cnt;
    for (int i = 0; i < 2 * n; i++)
        cnt[i + nums[i % n]]++;
    
    for (auto& [key, val] : cnt)
        if (val > 1) {
            cout << "NO" << nl;
            return;
        }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}