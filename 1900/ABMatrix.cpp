#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    if (n * a % m or n * a / m != b) {
        cout << "NO" << nl;
        return;
    }

    int g = gcd(m, a);
    v<string> ans(n, string(m, '0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a; j++)
            ans[i][(i * g + j) % m] = '1';

    cout << "YES" << nl;
    for (auto& s : ans)
        cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}