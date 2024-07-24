#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<array<int, 2>> b{{2, a[1] > a[0] ? 1 : -1}};
    for (int i = 2; i < n; i++)
        if (a[i] > a[i - 1]) {
            if (b.back()[1] == 1)
                b.back()[0]++;
            else
                b.push_back({2, 1});
        }
        else {
            if (b.back()[1] == -1)
                b.back()[0]++;
            else
                b.push_back({2, -1});
        }
    int m = b.size();
    
    int mx = 0, cnt = 0;
    bool adj = 0;
    for (int i = 0; i < m; i++)
        if (b[i][0] > mx) {
            mx = b[i][0];
            cnt = 1;
            adj = 0;
        }
        else if (b[i][0] == mx) {
            cnt++;
            if (b[i - 1][0] == mx)
                adj = 1;
        }
    
    if (cnt > 2 or (cnt == 2 and not adj)) {
        cout << 0 << nl;
        return;
    }

    if ((b.front()[0] == mx and b.front()[1] == -1)
            or (b.back()[0] == mx and b.back()[1] == 1)) {
        cout << 0 << nl;
        return;
    }

    if (cnt == 2) {
        for (int i = 0; i < m; i++)
            if (b[i][0] == mx) {
                if (b[i][0] == -1)
                    cout << 0 << nl;
                else if (mx & 1)
                    cout << 1 << nl;
                else
                    cout << 0 << nl;
                return;
            }
    }
    cout << 0 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}