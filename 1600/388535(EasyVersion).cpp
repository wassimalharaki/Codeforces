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

const int N = 17;

void solve() {
    int l, r; cin >> l >> r;
    int n = r - l + 1;

    v<int> nums(n), have(N), must(N);
    for (int& a : nums) cin >> a;

    for (int& a : nums)
        for (int i = 0; i < N; i++)
            if ((1 << i) & a)
                have[i]++;
    
    for (int a = l; a <= r; a++)
        for (int i = 0; i < N; i++)
            if ((1 << i) & a)
                must[i]++;

    int x = 0;
    for (int i = 0; i < N; i++)
        if (have[i] != must[i])
            x += (1 << i);

    cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}