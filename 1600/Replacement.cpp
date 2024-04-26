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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int curr = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == '.' and s[i - 1] == '.')
            curr++;
    
    while (m--) {
        int x; cin >> x;
        char c; cin >> c;
        x--;

        if (s[x] != '.' and c == '.') {
            if (x + 1 < n and s[x + 1] == '.')
                curr++;
            if (x - 1 >= 0 and s[x - 1] == '.')
                curr++;
        }
        else if (s[x] == '.' and c != '.') {
            if (x + 1 < n and s[x + 1] == '.')
                curr--;
            if (x - 1 >= 0 and s[x - 1] == '.')
                curr--;
        }
        s[x] = c;
        cout << curr << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}