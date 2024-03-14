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

/*
if x&y = 0, then f(x, y) = x
else f(x, y) = x - x&y
always losing
*/
void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    if (n == 1) {
        cout << nums[0];
        return;
    }

    v<int> bits(32);
    for (int& a : nums)
        for (int i = 0; i < 32; i++)
            if ((1 << i) & a)
                bits[i]++;
    
    int x = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 0; j < 32; j++)
            if ((1 << j) & nums[i])
                if (bits[j] == 1)
                    curr += 1 << j;
        if (curr > sum) x = i, sum = curr;
    }
    swap(nums[0], nums[x]);

    for (int& a : nums) cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}