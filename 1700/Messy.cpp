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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int i = n - 1;
    v<array<int, 2>> ans;
    for (int x = 0; x < k - 1; x++, i -= 2) {
        if (s[i] != ')')
            for (int j = i - 1; j >= 0; j--)
                if (s[j] == ')') {
                    reverse(s.begin() + j, s.begin() + i + 1);
                    ans.push_back({j + 1, i + 1});
                    break;
                }

        if (s[i - 1] != '(')
            for (int j = i - 2; j >= 0; j--)
                if (s[j] == '(') {
                    reverse(s.begin() + j, s.begin() + i);
                    ans.push_back({j + 1, i});
                    break;
                }
    }

    int x = (i + 1) / 2;
    while (i >= x) {
        if (s[i] != ')')
            for (int j = i - 1; j >= 0; j--)
                if (s[j] == ')') {
                    reverse(s.begin() + j, s.begin() + i + 1);
                    ans.push_back({j + 1, i + 1});
                    break;
                }
        i--;
    }

    cout << ans.size() << nl;
    for (auto& [x, y] : ans)
        cout << x << " " << y << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}