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
    sort(nums.begin(), nums.end());
    
    v<int> prefix(n + 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    set<int> have;
    auto f = [&](int l, int r, auto&& f) -> void {
        have.insert(prefix[r + 1] - prefix[l]);
        int mid = (nums[l] + nums[r]) / 2;
        if (mid == nums[l] and mid == nums[r]) return;
        int x = l;
        while (nums[x + 1] <= mid) x++;
        f(l, x, f); f(x + 1, r, f);
    };
    f(0, n - 1, f);

    while (q--) {
        int x; cin >> x;
        cout << (have.count(x) ? "Yes" : "No") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}