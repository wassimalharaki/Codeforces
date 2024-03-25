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
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        nums[i] = c - '0';
    }

    v<int> precomp(n);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
        precomp[i] = (sum += nums[i] - 1);
    sum = 0;

    map<int, int> cnt;
    for (int& a : precomp)
        cnt[a]++;

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += cnt[sum];
        cnt[precomp[i]]--;
        sum += nums[i] - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}