#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int get(v<int>& a, v<int>& b) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - b[i]);
    return ans;
}

int bruteforce(v<int>& a, v<int>& b) {
    int n = a.size(), ans = get(a, b);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            swap(b[i], b[j]);
            ans = max(ans, get(a, b));
            swap(b[i], b[j]);
        }
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int bl = INT_MIN, sr = INT_MAX;
    int ans = get(a, b), curr = ans;
    for (int i = 0; i < n; i++) {
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        if (sr < l)
            ans = max(ans, curr + (l - sr) * 2);
        if (bl > r)
            ans = max(ans, curr + (bl - r) * 2);
        sr = min(sr, r);
        bl = max(bl, l);
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