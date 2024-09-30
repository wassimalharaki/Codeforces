#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int a, b, c; cin >> a >> b >> c;

    int ops = 1e9;
    array<int, 3> ans;
    for (int i = 1; i <= c; i++)
        for (int j = i; j <= 2 * c; j += i) {
            int curr = abs(a - i) + abs(b - j) + min(c % j, j - c % j);
            if (curr < ops) {
                ops = curr;
                ans = {i, j, c + (c % j < j - c % j ? - c % j : j - c % j)};
            }
        }

    cout << ops << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}