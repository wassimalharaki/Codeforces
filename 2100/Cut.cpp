#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(const vector<S>& a) {
        int n = a.size(), k = 1 + (n ? __lg(n) : 0);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = __lg(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

const int K = 20;
const int N = 1e5 + 1;

void solve() {
    int n, q; cin >> n >> q;

    v<int> a(n), d(n, -1);
    v<v<int>> b(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }

    for (int i = 2; i < N; i++) {
        v<int> c;
        for (int j = i; j < N; j += i)
            for (int& k : b[j])
                c.push_back(k);
        sort(c.begin(), c.end());
        for (int j = 0; j < (int) c.size() - 1; j++)
            d[c[j + 1]] = max(d[c[j + 1]], c[j]);
    }
    sparse_table<int, op, e> max_table(d);

    v<v<int>> go(K, v<int>(n + 1, n));
    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (max_table.prod(i, mid + 1) >= i)
                go[0][i] = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
    }

    for (int i = 1; i < K; i++)
        for (int j = 0; j < n; j++)
            go[i][j] = go[i - 1][go[i - 1][j]];

    while (q--) {
        int l, r; cin >> l >> r; l--;
        int ans = 1;
        for (int i = K - 1; i >= 0; i--)
            if (go[i][l] < r)
                ans += (1ll << i), l = go[i][l];
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}