#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(n)
vector<int> manacher(string& t) {
    string s{'$'};
    for(char& c: t) s += string{'#', c};
    s += string{'#', '^'};

    int n = s.size() - 2, l = 1, r = 1;
    vector<int> p(n + 2);
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if(i + p[i] > r)
            l = i - p[i], r = i + p[i];
        p[i]--;
    }
    return vector<int>(begin(p) + 2, end(p) - 2);
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    v<int> man = manacher(s);

    v<int> diff(n);
    v<v<int>> cnt(n, v<int>(n));
    for (int l = 0; l < n; l++) {
        fill(diff.begin(), diff.end(), 0ll);
        cnt[l][l] = 1;

        int curr = 0;
        for (int r = l + 1; r < n; r++) {
            int x = man[r << 1], y = man[(r << 1) - 1];
            x = min(x, ((r - l) << 1) + 1);
            y = min(y, (r - l) << 1);
            curr++;
            diff[r + x / 2]++;
            if (y) curr++, diff[r + y / 2 - 1]++;
            cnt[l][r] = cnt[l][r - 1] + curr;
            curr -= diff[r];
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << cnt[l - 1][r - 1] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}