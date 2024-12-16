#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 26;
__int128_t fact[N];

// O(N)
void build() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = i * fact[i - 1];
}

// O(1)
__int128_t choose(int n, int r) {
    return fact[n] / fact[n - r] / fact[r];
}

v<map<int, int>> mitm(v<int>& a, int m, int s) {

    v<array<int, 2>> b;
    for (int& x : a)
        if (b.empty() or b.back()[0] != x)
            b.push_back({x, 1});
        else
            b.back()[1]++;
    int n = b.size();
    
    v<map<int, int>> curr(m + 1), next(m + 1), ans(m + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
        curr[0][0] = 1;
        for (int i = 0; i < n; i++) {
            if (!((1 << i) & mask)) continue;
            for (int j = 1; j <= b[i][1]; j++) {
                for (int k = 0; k <= (b[i][0] > 18 ? 0 : min(j, m)); k++) {
                    __int128_t sum = (j - k) * b[i][0]
                                    + (k ? k * fact[b[i][0]] : 0);
                    if (sum > s) break;
                    int ways = choose(b[i][1], j) * choose(j, k);
                    for (int l = 0; l <= m - k; l++) {
                        for (auto& [x, y] : curr[l]) {
                            if (x + sum > s) break;
                            next[l + k][x + sum] += y * ways;
                        }
                    }
                }
            }
            curr.swap(next);
            for (auto& x : next) x.clear();
        }
        for (int i = 0; i <= m; i++) {
            for (auto& [x, y] : curr[i]) {
                ans[i][x] += y;
            }
            curr[i].clear();
        }
    }
    return ans;
}

void solve() {
    int n, k, s; cin >> n >> k >> s;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    v<int> l, r;
    for (int i = 0; i < n; i++)
        if (i & 1)
            r.push_back(a[i]);
        else
            l.push_back(a[i]);
    
    auto left = mitm(l, k, s);
    auto right = mitm(r, k, s);
    int ans = 0;
    for (int i = 0; i <= k; i++)
        for (auto& [x, y] : right[i])
            for (int j = 0; j <= k - i; j++)
                if (left[j].count(s - x))
                    ans += y * left[j][s - x];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}