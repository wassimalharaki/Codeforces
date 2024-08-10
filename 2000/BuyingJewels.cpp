#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    if (k == n)
        cout << "YES\n1\n1\n";
    else if (k > (n + 1) / 2)
        cout << "NO\n";
    else
        cout << "YES\n2\n" << n - k + 1 << " 1\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}