#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return INT_MIN;
}

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
    int n, m; cin >> n >> m;

    v<int> a(n), pref(n + 1);
    for (int& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), pref.begin() + 1);
    sparse_table<int, op, e> max_table(pref);

    auto check = [&](int x, int k) -> int {
        int curr = pref.back() * k;
        if (curr >= x) return k * n;
        x -= curr;
        if (max_table.prod(0, n + 1) < x)
            return 0;

        int lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (max_table.prod(0, mid + 1) >= x)
                hi = mid - 1, ans = mid;
            else
                lo = mid + 1;
        }
        return k * n + ans;
    };

    if (pref.back() <= 0) {
        while (m--) {
            int x; cin >> x;
            if (max_table.prod(0, n + 1) < x) {
                cout << -1 << " ";
                continue;
            }

            int lo = 0, hi = n, ans = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (max_table.prod(0, mid + 1) >= x)
                    hi = mid - 1, ans = mid;
                else
                    lo = mid + 1;
            }
            cout << ans - 1 << " ";
        }
    }
    else {
        while (m--) {
            int x; cin >> x;
            int lo = 0, hi = (x + pref.back() - 1) / pref.back(), ans = 1e18;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int y = check(x, mid);

                if (y)
                    hi = mid - 1, ans = y;
                else
                    lo = mid + 1;
            }
            cout << ans - 1 << " ";
        }
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}