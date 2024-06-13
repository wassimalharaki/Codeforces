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
    int n = s.size();
    
    int m; cin >> m;
    v<int> a(m);
    for (int& x : a) cin >> x;

    array<int, 26> cnt;
    cnt.fill(0);
    for (char& c : s)
        cnt[c - 'a']++;

    string ans(m, '-');
    while (*max_element(a.begin(), a.end()) >= 0) {
        int x = 0;
        v<int> ind;
        for (int i = 0; i < m; i++)
            if (a[i] == 0) {
                x++;
                ind.push_back(i);
            }
        
        char c = 'z';
        while (cnt[c - 'a'] < x)
            cnt[c - 'a'] = 0, c--;
        cnt[c - 'a'] = 0;

        for (int& i : ind)
            ans[i] = c, a[i] = -1;

        for (int i = 0; i < m; i++)
            for (int& j : ind)
                a[i] -= abs(i - j);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}