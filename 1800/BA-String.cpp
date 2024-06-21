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
    int n, k, x; cin >> n >> k >> x; x--;
    string s; cin >> s;

    v<int> a;
    if (s.front() == '*')
        a.push_back(k + 1);
    for (int i = 1; i < n; i++)
        if (s[i] == '*') {
            if (s[i] == s[i - 1])
                a.back() += k;
            else
                a.push_back(k + 1);
        }
    
    v<int> suff(a.size() + 1);
    suff.back() = 1;
    for (int i = (int) a.size() - 1; i >= 0; i--)
        suff[i] = (a[i] >= LLONG_MAX / suff[i + 1] ? LLONG_MAX : a[i] * suff[i + 1]);

    v<int> b(a.size());
    for (int i = 0; i < a.size(); i++) {
        b[i] = x / suff[i + 1];
        x -= b[i] * suff[i + 1];
    }

    int j = 0;
    string ans;
    for (int i = 0; i < n; i++)
        if (s[i] == 'a')
            ans.push_back('a');
        else {
            ans += string(b[j++], 'b');
            while (i + 1 < n and s[i + 1] == '*')
                i++;
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