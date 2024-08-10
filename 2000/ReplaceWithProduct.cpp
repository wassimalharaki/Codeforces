#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int prod = 1;
    for (int i = 0; i < n; i++) {
        int can = LONG_LONG_MAX / prod;
        if (a[i] <= can)
            prod *= a[i];
        else {
            prod = LONG_LONG_MAX;
            break;
        }
    }

    if (prod >= 1e18) {
        int l = 0, r = n - 1;
        while (a[l] == 1)
            l++;
        while (a[r] == 1)
            r--;
        cout << l + 1 << " " << r + 1 << nl;
        return;
    }

    v<int> psum(n + 1);
    partial_sum(a.begin(), a.end(), psum.begin() + 1);
    v<int> pprod(n + 1); pprod[0] = 1;
    partial_sum(a.begin(), a.end(), pprod.begin() + 1, multiplies<int>());

    v<int> ind;
    for (int i = 0; i < n; i++)
        if (a[i] > 1)
            ind.push_back(i);
    
    int sum = 0, l = 1, r = 1;
    for (int i = 0; i < ind.size(); i++)
        for (int j = i; j < ind.size(); j++) {
            int x = ind[i], y = ind[j];
            int sum1 = psum[x];
            int prod = pprod[y + 1] / pprod[x];
            int sum2 = psum[n] - psum[y + 1];
            if (sum1 + prod + sum2 > sum) {
                sum = sum1 + prod + sum2;
                l = x + 1; r = y + 1;
            }
        }
    cout << l << " " << r << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}