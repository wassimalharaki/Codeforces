#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

mt19937_64 gen(random_device{}());
uniform_int_distribution<int> dist(0, 1e9 + 7);
const array<const int, 2> M{(int) 1e9 + 7, (int) 1e9 + 9};
const array<const int, 2> B{dist(gen), dist(gen)};
vector<vector<int>> p{{1}, {1}};

// O(n)
struct pair_hash {
    vector<vector<int>> h{{}, {}};

    pair_hash(string& s) {
        for (int j = 0; j < 2; j++) {
            h[j].resize(s.size() + 1);
            while (p[j].size() < s.size())
                p[j].push_back(p[j].back() * B[j] % M[j]);
        }

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
    int n = s.size();
    pair_hash hash(s);

    v<array<int, 2>> blocks{{0, 0}};
    for (int i = 1; i < n; i++)
        if (s[i - 1] == 'a' and s[i] == 'a')
            blocks.back()[1] = i;
        else
            blocks.push_back({i, i});

    if (blocks.size() == 1) {
        cout << (s[0] == 'a' ? n - 1 : 1) << nl;
        return;
    }

    v<int> bad;
    for (int i = 0; i < n; i++)
        if (s[i] != 'a') bad.push_back(i);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        set<array<int, 2>> have;
        bool ok = 1;
        array<int, 2> prev{0, 0};
        int min_a = 1e9;
        for (int j = bad[0]; j < n;) {
            if (j + i > n) {
                ok = 0; break;
            }
            have.insert(hash.get_hash(j, j + i));
            min_a = min(min_a, j - prev[1]);
            prev = {j, j + i};
            auto it = lower_bound(bad.begin(), bad.end(), j + i);
            if (it == bad.end()) break;
            j = *it;
        }
        if (ok and have.size() == 1)
            ans += min_a + 1;
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