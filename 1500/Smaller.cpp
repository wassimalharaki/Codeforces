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
    int q; cin >> q;

    v<int> s(26), t(26);
    s[0] = t[0] = 1;
    while (q--) {
        int d, k; cin >> d >> k;
        string x; cin >> x;
        if (d == 1)
            for (char& c : x)
                s[c - 'a'] += k;
        else
            for (char& c : x)
                t[c - 'a'] += k;
        
        int a = 0;
        for (int i = 0; i < 26; i++)
            if (t[i])
                a = i;
        
        if (a)
            cout << "YES" << nl;
        else {
            a = 0;
            for (int i = 0; i < 26; i++)
                if (s[i])
                    a = i;
            if (a != 0)
                cout << "NO" << nl;
            else
                cout << (s[0] < t[0] ? "YES" : "NO") << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}