#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string s; cin >> s;
    int a, b; cin >> a >> b;
    int n = s.size();

    v<char> left(n), right(n);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr = (10 * curr + s[i] - '0') % a;
        if (curr == 0) left[i] = 1;
    }

    curr = 0;
    int x = (b == 1 ? 0 : 1);
    for (int i = n - 1; i >= 0; i--) {
        curr = (curr + (s[i] - '0') * x) % b;
        x = x * 10 % b;
        if (curr == 0 and s[i] != '0') right[i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
        if (left[i] and right[i + 1]) {
            cout << "YES" << nl;
            cout << s.substr(0, i + 1) << nl;
            cout << s.substr(i + 1, n - (i + 1));
            return;
        }
    cout << "NO";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}