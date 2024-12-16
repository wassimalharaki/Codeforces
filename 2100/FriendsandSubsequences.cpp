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

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    sparse_table<int, op1, e1> mx(a);
    sparse_table<int, op2, e2> mn(b);

    long long ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        int x = mx.prod(l, r + 1), y = mn.prod(l, r + 1);
        if (x < y)
            r++;
        else if (x > y)
            r = max(r, ++l);
        else {
            int lo = r + 1, hi = n - 1, rb = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (mx.prod(l, mid + 1) == mn.prod(l, mid + 1))
                    rb = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            ans += rb - r + 1;
            r = max(r, ++l);
        }
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