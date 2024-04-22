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
    string s; cin >> s;
    int n = s.size();

    int ones = count(s.begin(), s.end(), '1');
    int zeroes = n - ones;

    v<int> left(ones + 1);
    for (int i = 0, j = 0; i < n; i++)
        if (s[i] == '0')
            left[j]++;
        else
            left[++j] = left[j];

    v<int> right(ones + 1);
    for (int i = n - 1, j = 0; i >= 0; i--)
        if (s[i] == '0')
            right[j]++;
        else
            right[++j] = right[j];

    auto check = [&](int k) {
        int x = 0;
        for (int i = 0; i <= k; i++)
            x = max(x, left[i] + right[k - i]);
        return zeroes - x <= k;
    };
    
    int lo = 0, hi = ones, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
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