#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v a(2, v<int>(n));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;
    
    auto go = [&](int i, int j, int k) -> bool {
        int lb = j;
        while (j + 1 < n) {
            if (k < a[i][j + 1])
                return 0;
            k++, j++;
        }
        if (k < a[!i][j])
            return 0;
        i = !i, k++;
        while (j > lb) {
            if (k < a[i][j - 1])
                return 0;
            k++, j--;
        }
        return 1;
    };
    
    auto check = [&](int k) -> bool {
        bool r = 0;
        int i = 0, j = 0;
        while (1) {
            if (r) {
                if (j == n - 1) return 1;
                if (k >= a[i][j + 1])
                    j++, k++;
                else
                    return go(!i, j, k - 1);
            }
            else {
                if (k >= a[!i][j])
                    i = !i, k++;
                else
                    return go(i, j, k);
            }
            r = !r;
        }
        return 1;
    };

    int lo = 0, hi = 1e10, ans = 1e10;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    cout << ans + 2 * n - 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}