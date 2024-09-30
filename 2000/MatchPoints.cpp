#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, z; cin >> n >> z;

    multiset<int> left, right;
    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        i < n / 2 ? left.insert(a[i]) : right.insert(a[i]);

    int ans = 0;
    for (int x : left) {
        auto it = right.lower_bound(x + z);
        if (it == right.end()) break;
        ans++;
        right.erase(it);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}