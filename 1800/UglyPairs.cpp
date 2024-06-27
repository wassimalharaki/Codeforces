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

bool valid(string& s) {
    for (int i = 0; i < s.size() - 1; i++)
        if (abs(s[i] - s[i + 1]) == 1)
            return 0;
    return 1;
}

void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();

    v<array<int, 2>> b{{s[0], 1}};
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            b.back()[1]++;
        else
            b.push_back({s[i], 1});
    int m = b.size();

    if (m <= 3) {
        do {
            string ans;
            for (int i = 0; i < m; i++)
                ans += string(b[i][1], char(b[i][0]));
            if (valid(ans)) {
                cout << ans << nl;
                return;
            }
        } while (next_permutation(b.begin(), b.end()));
        cout << "No answer" << nl;
    }
    else {
        string ans;
        for (int i = 0; i < m / 2; i++) {
            ans += string(b[i + m / 2][1], char(b[i + m / 2][0]));
            ans += string(b[i][1], char(b[i][0]));
        }
        if (m & 1)
            ans += string(b.back()[1], char(b.back()[0]));
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}