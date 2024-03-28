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

    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << - nums[0];
        return;
    }

    cout << 1 << " " << n - 1 << nl;
    for (int i = 0; i < n - 1; i++) {
        int k = (nums[i] % n + n) % n;
        cout << k * (n - 1) << " ";
        nums[i] += k * (n - 1);
    }
    cout << nl;

    cout << n << " " << n << nl;
    int k = (n - (nums.back() % n + n) % n) % n;
    cout << k << nl;
    nums.back() += k;

    cout << 1 << " " << n << nl;
    for (int& a : nums)
        cout << -a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}