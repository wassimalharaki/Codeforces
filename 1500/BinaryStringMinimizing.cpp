#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int at = 0;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        int need = i - at;
        if (k >= need) {
            k -= need;
            at++;
        }
        else {
            string t(at, '0');
            int x = at;
            for (char& c : s) {
                if (c == '0') {
                    if (x) x--;
                    else t.push_back(c);
                }
                else t.push_back(c);
            }
            s = t;
            ok = 1;
            break;
        }
    }
    if (ok) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') continue;
            if (at) {
                at--;
                continue;
            }
            while (k--)
                swap(s[i], s[i - 1]), i--;
            break;
        }
    }
    else
        s = string(at, '0') + string(n - at, '1');
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}