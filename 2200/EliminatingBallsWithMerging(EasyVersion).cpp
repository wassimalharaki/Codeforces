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

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n; cin >> n >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);
    sparse_table<int, op, e> max_table(a);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i + 1, x = a[i];
        while (l != -1 or r != n) {
            bool ok = 0;
            if (l != -1 and a[l] <= x) {
                ok = 1;
                int lo = 0, hi = l, lb = l;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (max_table.prod(mid, i + 1) <= x)
                        hi = mid - 1, lb = mid;
                    else
                        lo = mid + 1;
                }
                x += pref[l + 1] - pref[lb];
                l = lb - 1;
            }
            if (r != n and a[r] <= x) {
                ok = 1;
                int lo = r, hi = n - 1, rb = r;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (max_table.prod(i, mid + 1) <= x)
                        lo = mid + 1, rb = mid;
                    else
                        hi = mid - 1;
                }
                x += pref[rb + 1] - pref[r];
                r = rb + 1;
            }
            if (not ok) break;
        }
        ans += (l == -1 and r == n);
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