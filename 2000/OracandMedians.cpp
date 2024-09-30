#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (n == 1) {
        cout << (a[0] == k ? "YES" : "NO") << nl;
        return;
    }
    
    if (count(a.begin(), a.end(), k) == 0) {
        cout << "NO" << nl;
        return;
    }

    bool ans = 0;
    int curr = 0;
    v<int> pref(n + 1), ind;
    for (int i = 0; i < n; i++) {
        curr += a[i] < k ? -1 : 1;
        pref[i + 1] = min(pref[i], curr);
        if (i - 1 >= 0)
            ans |= curr - pref[i - 1] > 0;
    }
    cout << (ans ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}