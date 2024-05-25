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
    int n; cin >> n;
    string s; cin >> s;

    v<int> right(n + 1), left(n + 1);
    int curr = 0, prev = 'x';
    for (int i = n - 1; i >= 0; i--) {
        s[i] == prev ? curr = 1 : curr++;
        prev = s[i];
        if (s[i] == 'R') right[i] = curr;
    }
    
    curr = 0, prev = 'x';
    for (int i = 0; i < n; i++) {
        s[i] == prev ? curr = 1 : curr++;
        prev = s[i];
        if (s[i] == 'L') left[i + 1] = curr;
    }

    for (int i = 0; i <= n; i++)
        cout << left[i] + right[i] + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}