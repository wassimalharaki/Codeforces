#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op1(int a, int b) { return max(a, b); }
int e1() { return 0; }
int op2(int a, int b) { return min(a, b); }
int e2() { return INT_MAX; }

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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sparse_table<int, op1, e1> mx(a);
    sparse_table<int, op2, e2> mn(a);

    auto get_end = [&](int l, int r, int x) -> array<int, 2> {
        array<int, 2> y{l, l};
        {
            int lo = l, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (mx.prod(mid, r + 1) <= x)
                    y[0] = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        {
            int lo = l, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (mx.prod(mid, r + 1) >= x)
                    y[1] = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return y;
    };

    auto get_beg = [&](int l, int r, int x) -> array<int, 2> {
        array<int, 2> y{r, r};
        {
            int lo = l, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (mn.prod(l, mid + 1) <= x)
                    y[0] = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        {
            int lo = l, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (mn.prod(l, mid + 1) >= x)
                    y[1] = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return y;
    };

    for (int i = 0; i < n - 2; i++) {
        int x = mx.prod(0, i + 1);
        array<int, 2> m = get_beg(i + 1, n - 2, x);
        array<int, 2> r = get_end(i + 2, n - 1, x);
        if (mx.prod(r[0], n) != x) continue;
        if (mn.prod(i + 1, m[0] + 1) != x) continue;
    
        int j = max(m[0], r[0] - 1);
        if (j + 1 > r[1]) continue;
        if (j > m[1]) continue;

        cout << "YES" << nl;
        cout << i + 1 << " " << j - i << " " << n - j - 1 << nl;
        return;
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}