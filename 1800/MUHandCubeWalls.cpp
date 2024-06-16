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

// O(n)
struct pair_hash {
    vector<vector<int>> h{{}, {}};

    pair_hash(v<int>& a) {
        for (int j = 0; j < 2; j++) {
            h[j].resize(a.size() + 1);
            while (p[j].size() < a.size())
                p[j].push_back(p[j].back() * B[j] % M[j]);
        }

        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < 2; j++)
                h[j][i + 1] = (h[j][i] * B[j] % M[j] + a[i]) % M[j];
    }

    array<int, 2> get_hash(int l, int r) {
        int x = h[0][r] - h[0][l] * p[0][r - l];
        int y = h[1][r] - h[1][l] * p[1][r - l];
        return {(x % M[0] + M[0]) % M[0], (y % M[1] + M[1]) % M[1]};
    }
};

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<int> diff_a(n - 1), diff_b(m - 1);
    for (int i = 0; i < n - 1; i++)
        diff_a[i] = a[i + 1] - a[i];
    for (int i = 0; i < m - 1; i++)
        diff_b[i] = b[i + 1] - b[i];

    int ans = 0;
    pair_hash hash_a(diff_a), hash_b(diff_b);
    for (int i = 0; i < n - m + 1; i++)
        ans += hash_b.get_hash(0, m - 1) == hash_a.get_hash(i, i + m - 1);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}