#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (a.back() == 0) {
        cout << 0 << nl;
        return;
    }

    int z = 0;
    reverse(a.begin(), a.end());
    while (a.back() == 0) a.pop_back(), z++;
    reverse(a.begin(), a.end());
    n = a.size();

    while (n > 1) {
        v<int> b;
        if (z) b.push_back(a[0]), z--;
        for (int i = 0; i < n - 1; i++)
            if (a[i + 1] - a[i])
                b.push_back(a[i + 1] - a[i]);
            else
                z++;
        
        sort(b.begin(), b.end());
        a.swap(b);
        n = a.size();
    }
    cout << (n ? a[0] : 0) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}