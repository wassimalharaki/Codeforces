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

    v<int> ans(n, -1), free;
    int mex = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == mex)
            free.push_back(i);
        else {
            ans[i] = mex;
            for (int x = mex + 1; x < nums[i]; x++)
                ans[free.back()] = x, free.pop_back();
            mex = nums[i];
        }
    
    while (free.size())
        ans[free.back()] = 1e6, free.pop_back();
    
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}