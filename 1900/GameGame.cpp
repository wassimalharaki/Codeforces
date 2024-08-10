#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int y = accumulate(a.begin(), a.end(), 0ll, bit_xor());

    if (y == 0) {
        cout << "DRAW" << nl;
        return;
    }

    int msb = __lg(y), on = 0, off = 0;
    for (int& x : a)
        1 << msb & x ? on++ : off++;
    if (on == 1)
        cout << "WIN" << nl;
    else if (on >> 1 & 1)
        cout << (off & 1 ? "WIN" : "LOSE") << nl;
    else
        cout << "WIN" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}