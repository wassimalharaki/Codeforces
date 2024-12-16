#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    if ((n & 1) and a[n / 2] != b[n / 2]) {
        cout << "NO" << nl;
        return;
    }

    map<int, multiset<int>> ok;
    for (int i = 0; i < n / 2; i++) {
        ok[a[i]].insert(a[n - i - 1]);
        ok[a[n - i - 1]].insert(a[i]);
    }

    for (int i = 0; i < n / 2; i++)
        if (ok[b[i]].find(b[n - i - 1]) == ok[b[i]].end()) {
            cout << "NO" << nl;
            return;
        }
        else {
            ok[b[i]].erase(ok[b[i]].find(b[n - i - 1]));
            ok[b[n - i - 1]].erase(ok[b[n - i - 1]].find(b[i]));
        }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}