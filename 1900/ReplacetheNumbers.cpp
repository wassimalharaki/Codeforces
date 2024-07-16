#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5e5 + 1;

void solve() {
    int q; cin >> q;

    int n = 0;
    v<array<int, 3>> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] == 2)
            cin >> a[i][2];
        else n++;
    }

    v<int> ans(n), id(N);
    iota(id.begin(), id.end(), 0ll);
    for (int i = q - 1; i >= 0; i--) {
        if (a[i][0] == 1)
            ans[--n] = id[a[i][1]];
        else
            id[a[i][1]] = id[a[i][2]];
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}