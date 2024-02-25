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

    auto get = [&](char c) -> int {
        int l = 0, r = 0;
        int good = 0, bad = 0;
        int ans = 1;
        while (r < n)
            if (bad > k)
                s[l++] == c ? good-- : bad--;
            else {
                s[r++] == c ? good++ : bad++;
                if (bad <= k) ans = max(ans, r - l);
            }
        return ans;
    };
    cout << max(get('a'), get('b'));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}