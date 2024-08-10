#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S)>
struct sparse_table {
    v<v<S>> d;

    sparse_table(v<S>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d = v<v<S>>(k, v<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();

    v<int> open(n, 1), close(n), diff(n, n);
    diff[0] = 1;
    for (int i = 1; i < n; i++) {
        open[i] = open[i - 1] + (s[i] == '(');
        close[i] = close[i - 1] + (s[i] == ')');
        diff[i] = open[i] - close[i];
    }

    sparse_table<int, [](int a, int b) {
        return max(a, b);
    }> max_table(diff);

    v<v<int>> bad(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int d = open[i] - close[i];

        int l = i + 1, r = n - 1, j = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = max_table.prod(i + 1, mid + 1);
            if (x - diff[i] >= d + 1)
                j = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        bad[j].push_back(i);
    }

    int ans = 0;
    v<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        for (auto& j : bad[i])
            cnt[open[j] - close[j]]--;
        ans += cnt[open[i] - close[i]]++;
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