#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[x]++;
    }

    int ans = n * (n - 1) / 2;
    v<int> pie(n + 1, -1), alive(n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] or alive[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                a[i] += a[j];
                pie[j] -= pie[i];
                alive[j] = 1;
            }
            ans += a[i] * (a[i] - 1) / 2 * pie[i];
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