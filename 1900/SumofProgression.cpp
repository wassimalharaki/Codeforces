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
    int n, q; cin >> n >> q;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int B = sqrt(n);
    v<v<v<int>>> precomp(B + 1);
    v<v<v<int>>> precomp_weighted(B + 1);
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < i; j++) {
            int sum = 0, sum_weighted = 0, x = 1;
            precomp_weighted[i].push_back(v<int>());
            precomp[i].push_back(v<int>());
            for (int k = j; k < n; k += i) {
                sum += nums[k];
                sum_weighted += x++ * nums[k];
                precomp[i][j].push_back(sum);
                precomp_weighted[i][j].push_back(sum_weighted);
            }
        }
    }

    auto bf = [&](int s, int d, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += (i + 1) * nums[s + i * d];
        return sum;
    };

    while (q--) {
        int s, d, k; cin >> s >> d >> k; --s;
        if (d >= B)
            cout << bf(s, d, k) << " ";
        else {
            if (s < d)
                cout << precomp_weighted[d][s][s / d + k - 1] << " ";
            else {
                int rem_weighted = precomp_weighted[d][s % d][s / d - 1];
                int add_weighted = precomp_weighted[d][s % d][s / d + k - 1];
                int rem = precomp[d][s % d][s / d - 1];
                int add = precomp[d][s % d][s / d + k - 1];
                cout << add_weighted - rem_weighted - s / d * (add - rem) << " ";
            }
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