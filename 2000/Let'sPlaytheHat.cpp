#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int small = n / m, big = (n + m - 1) / m, times = n % m;
    if (small == big) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                if (j % small == 0)
                    cout << small << " ";
                cout << j + 1 << " ";
                if ((j + 1) % small == 0)
                    cout << nl;
            }
        }
        cout << nl;
        return;
    }

    int start = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < times; j++) {
            cout << big << " ";
            for (int l = 0; l < big; l++) {
                cout << start + 1 << " ";
                start = (start + 1) % n;
            }
            cout << nl;
        }
        int curr = start;
        for (int j = 0; j < m - times; j++) {
            cout << small << " ";
            for (int l = 0; l < small; l++) {
                cout << curr + 1 << " ";
                curr = (curr + 1) % n;
            }
            cout << nl;
        }
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}