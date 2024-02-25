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
    int k; cin >> k;
    string s = "codeforces";
    int a = 1, i = 0;
    v<int> nums(10, 1);
    while (a < k) {
        int& b = nums[i % 10];
        a = a / b * (b + 1);
        b++; i++;
    }
    for (int i = 0; i < 10; i++)
        cout << string(nums[i], s[i]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}