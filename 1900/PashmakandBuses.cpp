#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int get(int n, int k) {
    int x = k, ans = 1;
    while (x < n) {
        x *= k;
        ans++;
    }
    return ans;
}

void solve() {
    int n, k, d; cin >> n >> k >> d;

    if (k == 1 and n == 1) {
        for (int i = 0; i < d; i++)
            cout << 1 << nl;
        return;
    }

    if (k == 1) {
        cout << -1 << nl;
        return;
    }

    if (d == 1 and k < n) {
        cout << -1 << nl;
        return;
    }

    if (d == 1) {
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
        cout << nl;
        return;
    }

    if (k >= n) {
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++)
                cout << j + 1 << " ";
            cout << nl;
        }
        return;
    }

    if (d < get(n, k)) {
        cout << -1 << nl;
        return;
    }

    int x = 1;
    for (int i = 0; i < d; i++) {
        int y = 1, cnt = x;
        for (int j = 0; j < n; j++) {
            cout << y << " ";
            if (--cnt == 0) {
                y = y % k + 1;
                cnt = x;
            }
        }
        cout << nl;
        x *= k;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}