#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<v<int>> nums(n, v<int>(5));
    for (v<int>& a : nums)
        for (int& b : a)
            cin >> b;

    auto is_sup = [&](int i, int j) {
        int cnt = 0;
        for (int k = 0; k < 5; k++)
            if (nums[i][k] < nums[j][k])
                cnt++;
        return cnt >= 3;
    };
    
    auto div = [&](int l, int r, auto&& div) -> int {
        if (l == r) return l;

        int a = (l + r) / 2;
        int i = div(l, a, div);
        int j = div(a + 1, r, div);
        if (i == -2 and j == -2)
            return -2;

        if (i == -2) {
            for (int k = l; k <= a; k++)
                if (is_sup(k, j))
                    return -2;
            return j;
        }

        if (j == -2) {
            for (int k = a + 1; k <= r; k++)
                if (is_sup(k, i))
                    return -2;
            return i;
        }

        if (is_sup(i, j)) {
            for (int k = a + 1; k <= r; k++)
                if (is_sup(k, i))
                    return -2;
            return i;
        }
        else {
            for (int k = l; k <= a; k++)
                if (is_sup(k, j))
                    return -2;
            return j;
        }
    };
    cout << div(0, n - 1, div) + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}