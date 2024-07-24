#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int a, b, k; cin >> a >> b >> k;

    if (a == 0) {
        if (k == 0) {
            cout << "Yes" << nl;
            cout << string(b, '1') << nl;
            cout << string(b, '1') << nl;
        }
        else
            cout << "No" << nl;
        return;
    }

    if (b == 1) {
        if (k == 0) {
            cout << "Yes" << nl;
            cout << 1 << string(a, '0') << nl;
            cout << 1 << string(a, '0') << nl;
        }
        else
            cout << "No" << nl;
        return;
    }

    if (k > a + b - 2) {
        cout << "No" << nl;
        return;
    }

    string s(a + b, '0'), t(a + b, '0');
    s[0] = t[0] = s[1] = t[1 + k] = '1';
    for (int i = 0, j = b - 2; i < a + b and j; i++)
        if (s[i] == t[i] and t[i] == '0')
            s[i] = t[i] = '1', j--;

    cout << "Yes" << nl;
    cout << s << nl << t << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}