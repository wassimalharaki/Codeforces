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
    set<int, greater<int>> ans;
    for (int& a : nums) cin >> a;
 
    set<int> missing;
    for (int i = 0; i < n; i++)
        missing.insert(nums[i] + i + 1);
    
    for (int i = 0; i < n; i++) {
        int a = nums[i] + i + 1;
        if (not ans.count(a)) {
            ans.insert(a);
            missing.erase(a);
            if (not ans.count(a - 1))
                missing.insert(a - 1);
        }
        else {
            auto it = --missing.lower_bound(a);
            int y = *it;
            if (a - i <= y) {
                ans.insert(y);
                missing.erase(y);
                if (not ans.count(y - 1))
                    missing.insert(y - 1);
            }
        }
    }
 
    for (int i : ans)
        cout << i << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}