#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

//O(nlog(n))
template <class S, S (*op)(S, S)>
struct sparse_table {
    const int n = 25;
    vector<vector<S>> d;

    sparse_table(vector<S>& nums) {
        d = vector<vector<S>>(n + 1, vector<S>(nums.size()));
        copy(nums.begin(), nums.end(), d[0].begin());

        for (int i = 1; i <= n; i++)
            for (int j = 0; j + (1 << i) <= nums.size(); j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    sparse_table<int, [](int a, int b) {return max(a, b);}> stable_a(a);
    sparse_table<int, [](int a, int b) {return min(a, b);}> stable_b(b);

    v<v<int>> at(n + 1);
    for (int i = 0; i < n; i++)
        at[a[i]].push_back(i);

    for (int i = 0; i < n; i++)
        if (a[i] > b[i]) {
            cout << "NO" << nl;
            return;
        }
        else if (a[i] < b[i]) {
            if (at[b[i]].size() == 0) {
                cout << "NO" << nl;
                return;
            }

            auto it = lower_bound(at[b[i]].begin(), at[b[i]].end(), i);
            if (it == at[b[i]].end()) {
                it--;
                int x = stable_a.prod(*it, i + 1);
                int y = stable_b.prod(*it, i + 1);
                if (x > b[i] or y < b[i]) {
                    cout << "NO" << nl;
                    return;
                }
            }
            else if (it == at[b[i]].begin()) {
                int x = stable_a.prod(i, *it + 1);
                int y = stable_b.prod(i, *it + 1);
                if (x > b[i] or y < b[i]) {
                    cout << "NO" << nl;
                    return;
                }
            }
            else {
                int x = stable_a.prod(i, *it + 1);
                int y = stable_b.prod(i, *it + 1);
                if (x == b[i] and y >= b[i]) continue;
                --it;
                x = stable_a.prod(*it, i + 1);
                y = stable_b.prod(*it, i + 1);
                if (x > b[i] or y < b[i]) {
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}