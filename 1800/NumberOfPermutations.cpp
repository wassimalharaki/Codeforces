#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int mod = 998244353;
const int N = 3e5 + 1;
int fact[N];

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];
    
    sort(a.begin(), a.end());
    v<array<int, 2>> left{{0, 0}};
    for (int i = 1; i < n; i++)
        if (a[i][0] == a[i - 1][0])
            left.back()[1] = i;
        else
            left.push_back({i, i});

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        if (l[1] == r[1])
            return l[0] < r[0];
        return l[1] < r[1];
    });
    v<array<int, 2>> right{{0, 0}};
    for (int i = 1; i < n; i++)
        if (a[i][1] == a[i - 1][1])
            right.back()[1] = i;
        else
            right.push_back({i, i});
    
    v<array<int, 2>> both{{0, 0}};
    for (int i = 1; i < n; i++)
        if (a[i][0] == a[i - 1][0] and a[i][1] == a[i - 1][1])
            both.back()[1] = i;
        else
            both.push_back({i, i});

    int bad_left = 1, bad_right = 1, bad_both = is_sorted(a.begin(), a.end());
    for (auto& [l, r] : left)
        bad_left = bad_left * fact[r - l + 1] % mod;
    for (auto& [l, r] : right)
        bad_right = bad_right * fact[r - l + 1] % mod;
    for (auto& [l, r] : both)
        bad_both = bad_both * fact[r - l + 1] % mod;
    cout << ((fact[n] - bad_left - bad_right + bad_both) % mod + mod) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;
    int T = 1;
    // cin >> T;
    while (T--) solve();
}