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

    set<int> have;
    for (int i = 1; i <= n; i++)
        have.insert(i);
    
    for (int i = 0; i < n; i++)
        if (have.count(nums[i])) {
            cout << nums[i] << " ";
            have.erase(nums[i]);
        }
        else {
            cout << *have.begin() << " ";
            have.erase(have.begin());
        }
    cout << nl;

    for (int i = 1; i <= n; i++)
        have.insert(i);

    for (int i = 0; i < n; i++) {
        auto it = --have.upper_bound(nums[i]);
        cout << *it << " ";
        have.erase(it);
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