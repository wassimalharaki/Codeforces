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

bool is_pal(string& s) {
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
            return 0;
    return 1;
}

void solve() {
    int n; cin >> n;

    v<string> s(n);
    for (string& t : s) cin >> t;

    set<string> threes, real_twos, twos;
    for (string& t : s) {
        if (is_pal(t)) {
            cout << "YES" << nl;
            return;
        }

        if (t.size() == 2) {
            string u = t;
            reverse(u.begin(), u.end());
            if (twos.count(u)) {
                cout << "YES" << nl;
                return;
            }
            twos.insert(t);
            real_twos.insert(t);
        }

        if (t.size() == 3) {
            string u = t;
            reverse(u.begin(), u.end());
            if (threes.count(u)) {
                cout << "YES" << nl;
                return;
            }
            u.pop_back();
            if (real_twos.count(u)) {
                cout << "YES" << nl;
                return;
            }
            threes.insert(t);
            t.pop_back();
            twos.insert(t);
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}