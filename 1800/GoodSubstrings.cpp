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

mt19937_64 gen(random_device{}());
uniform_int_distribution<int> dist(0, 1e9 + 7);
const array<const int, 2> M{(int) 1e9 + 7, (int) 1e9 + 9};
const array<const int, 2> B{dist(gen), dist(gen)};
vector<vector<int>> p{{1}, {1}};

struct hashed_string {
    vector<v<int>> h{{}, {}};

    hashed_string(const string& s) {
        h[0].resize(s.size() + 1);
        h[1].resize(s.size() + 1);

        for (int j = 0; j < 2; j++)
            while (p[j].size() < s.size())
                p[j].push_back(p[j].back() * B[j] % M[j]);

        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < 2; j++)
                h[j][i + 1] = (h[j][i] * B[j] % M[j] + s[i]) % M[j];
    }

    array<int, 2> get_hash(int l, int r) {
        int x = h[0][r] - h[0][l] * p[0][r - l];
        int y = h[1][r] - h[1][l] * p[1][r - l];
        return {(x % M[0] + M[0]) % M[0], (y % M[1] + M[1]) % M[1]};
    }
};

void solve() {
    string s; cin >> s;
    string t; cin >> t;
    int m; cin >> m;
    int n = s.size();

    hashed_string hs(s);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        set<array<int, 2>> curr;
        for (int j = 0; j < i; j++)
            x += t[s[j] - 'a'] == '0';
        if (x <= m)
            curr.insert(hs.get_hash(0, i));
        for (int j = i; j < n; j++) {
            x -= t[s[j - i] - 'a'] == '0';
            x += t[s[j] - 'a'] == '0';

            if (x <= m)
                curr.insert(hs.get_hash(j - i + 1, j + 1));
        }
        ans += curr.size();
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}