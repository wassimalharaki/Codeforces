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

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> prefix(n + 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    multiset<int> have{accumulate(nums.begin(), nums.end(), 0ll)};
    set<int> ok{-1, n};
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        auto it = ok.lower_bound(x);
        int r = *it, l = *(--it);
        ok.insert(x);

        int sum = prefix[r] - prefix[l + 1];
        have.erase(have.find(sum));
        have.insert(prefix[x] - prefix[l + 1]);
        have.insert(prefix[r] - prefix[x + 1]);
        cout << *have.rbegin() << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}