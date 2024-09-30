#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return min(a, b); }
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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int rot = max_element(a.begin(), a.end()) - a.begin() + 1;
    rotate(a.begin(), a.begin() + rot, a.end());

    sparse_table<int, op, e> min_table(a);
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    
    v<int> dp(n), gt(n, -1);
    {
        int mx = 0;
        for (int i = n - 1; i < 2 * n; i++) {
            mx = max(a[i], mx);
            if (a[i] < (mx + 1) / 2) {
                dp[n - 1] *= -1; break;
            }
            dp[n - 1]--;
        }
        if (dp[n - 1] < 0) dp[n - 1] = -1;
    }
    
    stack<int> mono; mono.push(n - 1);
    for (int i = n - 1; i >= 0; i--) {
        while (a[mono.top()] < a[i])
            mono.pop();
        gt[i] = mono.top();
        mono.push(i);
    }

    for (int i = n - 2; i >= 0; i--) {
        int lo = i, hi = n - 1, j = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (min_table.prod(i, mid + 1) < (a[i] + 1) / 2)
                hi = mid - 1, j = mid;
            else
                lo = mid + 1;
        }

        if (j != -1 and j < gt[i])
            dp[i] = j - i;
        else if (dp[gt[i]] == -1)
            dp[i] = -1;
        else
            dp[i] = dp[gt[i]] + gt[i] - i;
    }
    rotate(dp.begin(), dp.begin() + n - rot, dp.end());

    for (int& x : dp)
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