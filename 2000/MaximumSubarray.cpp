#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k, x; cin >> n >> k >> x;

    v<int> a(n);
    for (int& y : a) cin >> y;

    multiset<int> min;
    auto add = [&](int y) { min.insert(y); };
    auto rem = [&](int y) { min.erase(min.find(y)); };
    auto get = [&]() { return *min.begin(); };
    add(0);

    if (x > 0) {
        int ans = LLONG_MIN;
        v<int> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = (i ? pref[i - 1] : 0) + a[i] - x;
            add(pref[i]);

            for (int j = max(0ll, i - k + 1); j <= i; j++) {
                rem(pref[j]);
                pref[j] = (j ? pref[j - 1] : 0) + a[j] + x;
                add(pref[j]);
            }
            ans = max(ans, pref[i] - get());
            for (int j = max(0ll, i - k + 1); j <= i; j++) {
                rem(pref[j]);
                pref[j] = (j ? pref[j - 1] : 0) + a[j] - x;
                add(pref[j]);
            }
        }
        cout << ans << nl;
    }
    else {
        int ans = LLONG_MIN;
        v<int> pref(n);
        for (int i = 0; i < n - k; i++) {
            pref[i] = (i ? pref[i - 1] : 0) + a[i] - x;
            add(pref[i]);
            ans = max(ans, pref[i] - get());
        }

        for (int i = n - k; i < n; i++) {
            add(pref[i]);
            for (int j = 0; j <= i - (n - k); j++) {
                rem(pref[j]);
                pref[j] = (j ? pref[j - 1] : 0) + a[j] + x;
                add(pref[j]);
            }
            for (int j = i - (n - k) + 1; j <= i; j++) {
                rem(pref[j]);
                pref[j] = (j ? pref[j - 1] : 0) + a[j] - x;
                add(pref[j]);
            }
            ans = max(ans, pref[i] - get());
        }
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}