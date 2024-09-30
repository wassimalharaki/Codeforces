#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(k + 1);
    for (int i = 0; i < n; i++) {
        int c, d, h; cin >> c >> d >> h;
        a[c] = max(a[c], d * h);
    }

    for (int i = 1; i <= k; i++)
        for (int j = i; j <= k; j += i)
            a[j] = max(a[j], j / i * a[i]);
    
    for (int i = 1; i <= k; i++)
        a[i] = max(a[i], a[i - 1]);

    int m; cin >> m;
    while (m--) {
        int d, h; cin >> d >> h;
        auto it = upper_bound(a.begin(), a.end(), d * h);
        cout << (it == a.end() ? -1 : it - a.begin()) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}