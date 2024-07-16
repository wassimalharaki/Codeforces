#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    v<v<int>> a(k);
    for (int i = 0; i < n; i++)
        a[i % k].push_back(s[i] - '0');

    for (auto& x : a) {
        while (x.size() and x.back() == 0) x.pop_back();
        reverse(x.begin(), x.end());
        while (x.size() and x.back() == 0) x.pop_back();
        reverse(x.begin(), x.end());
    }
    
    int ans = 1e18, ones = count(s.begin(), s.end(), '1');
    for (auto& x : a) {
        int curr = ones - count(x.begin(), x.end(), 1);
        int m = x.size();

        if (m <= 2) {
            ans = min(ans, curr);
            continue;
        }

        v<int> left(m), right(m), pref(m + 1);
        partial_sum(x.begin(), x.end(), pref.begin() + 1);
        int l = 0, r = m, pad_left = 0, pad_right = 0;

        for (int i = 1; i < m; i++) {
            left[i] = (x[i] == 0) + pad_left;
            int lo = pref[i] - pref[l];
            int lz = i - l - lo;

            if (lz <= lo)
                left[i] += lz;
            else {
                pad_left += lo;
                left[i] += lo;
                l = i;
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            right[i] = (x[i] == 0) + pad_right;
            int ro = pref[r] - pref[i + 1];
            int rz = r - (i + 1) - ro;

            if (rz <= ro)
                right[i] += rz;
            else {
                pad_right += ro;
                right[i] += ro;
                r = i + 1;
            }
        }

        for (int i = 0; i < m; i++)
            ans = min(ans, curr + left[i] + right[i]);
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