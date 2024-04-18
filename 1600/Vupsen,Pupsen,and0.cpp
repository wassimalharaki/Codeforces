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

    v<int> ans;
    if (n & 1) {
        for (int i = 0; i < n - 3; i += 2)
            ans.push_back(nums[i + 1]),
            ans.push_back(- nums[i]);

        int a, b, c;
        tie(a, b, c) = {nums[n - 3], nums[n - 2], nums[n - 1]};
        if (a * b > 0) {
            ans.push_back(-c);
            ans.push_back(-c);
            ans.push_back(a + b);
        }
        else if (a * c > 0) {
            ans.push_back(-b);
            ans.push_back(a + c);
            ans.push_back(-b);
        }
        else {
            ans.push_back(b + c);
            ans.push_back(-a);
            ans.push_back(-a);
        }
    }
    else {
        for (int i = 0; i < n; i += 2)
            ans.push_back(nums[i + 1]),
            ans.push_back(- nums[i]);
    }

    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}