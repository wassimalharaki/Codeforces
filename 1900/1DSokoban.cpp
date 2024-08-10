#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int solve(v<int>& a, v<int>& b) {
    int n = a.size(), m = b.size();
    if (n == 0 or m == 0) return 0;

    v<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + binary_search(b.begin(), b.end(), a[i]);
    
    int ans = pref.back();
    for (int i = 0; i < m; i++) {
        int lo = 0, hi = n, x = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int y = lower_bound(a.begin(), a.end(), b[i] + mid) - a.begin();

            if (y >= mid)
                lo = mid + 1, x = mid;
            else
                hi = mid - 1;
        }

        int y = upper_bound(b.begin(), b.end(), b[i] + x - 1)
              - lower_bound(b.begin(), b.end(), b[i]);
        ans = max(ans, y + pref[n] - pref[x]);
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;

    v<int> neg_a, pos_a, neg_b, pos_b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x > 0 ? pos_a.push_back(x) : neg_a.push_back(-x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        x > 0 ? pos_b.push_back(x) : neg_b.push_back(-x);
    }

    reverse(neg_a.begin(), neg_a.end());
    reverse(neg_b.begin(), neg_b.end());
    
    cout << solve(neg_a, neg_b) + solve(pos_a, pos_b) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}