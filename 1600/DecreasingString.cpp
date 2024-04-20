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
    string s; cin >> s;
    int p; cin >> p; p--;

    int n = s.size();
    while (p - n >= 0)
        p -= n--;
    
    int x = s.size() - n;
    string t{'$'};
    for (int i = 0; i < s.size(); i++) {
        while (x and s[i] < t.back()) {
            t.pop_back();
            x--;
        }
        t.push_back(s[i]);
    }
    t.erase(t.begin());

    while (t.size() > n)
        t.pop_back();
    cout << t[p];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}