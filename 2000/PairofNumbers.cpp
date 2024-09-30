#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return gcd(a, b);
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
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
    sparse_table<int, op, e> st(a);

    int k = 0;
    v<int> ans;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        {
            int lo = i, hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (st.prod(i, mid + 1) == a[i])
                    lo = mid + 1, r = mid;
                else
                    hi = mid - 1;
            }
        }
        {
            int lo = 0, hi = i;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (st.prod(mid, i + 1) == a[i])
                    hi = mid - 1, l = mid;
                else
                    lo = mid + 1;
            }
        }
        if (r - l > k) {
            k = r - l;
            ans = {l + 1};
        }
        else if (r - l == k)
            ans.push_back(l + 1);
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    cout << ans.size() << " " << k << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}