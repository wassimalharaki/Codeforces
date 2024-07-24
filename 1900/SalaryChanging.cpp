#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, s; cin >> n >> s;

    v<array<int, 2>> a(n);
    for (auto& [l, r] : a)
        cin >> l >> r;

    auto check = [&](int k) -> int {
        int ans = 0, cnt1 = 0, cnt2 = 0;
        v<array<int, 2>> b;
        for (auto& [l, r] : a)
            if (r < k)
                cnt1++, ans += l;
            else if (k < l)
                cnt2++, ans += l;
            else
                b.push_back({l, r});
        if (cnt2 > n / 2) return 1;
        if (cnt1 > n / 2) return 0;

        int left = n / 2 - cnt1;

        sort(b.begin(), b.end());
        for (int i = 0; i < (int) b.size(); i++)
            ans += (i < left ? b[i][0] : k);
        return ans <= s;
    };
    
    int lo = 1, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
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