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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    unsigned int n, s; cin >> n >> s;

    auto f = [](int n) -> int {
        int sum = 0;
        string s = to_string(n);
        for (int i = 0; i < s.size(); i++)
            sum += s[i] - '0';
        return sum;
    };

    int ans = 0, i = 0;
    while (f(n) > s) {
        string s = to_string(n);
        reverse(all(s));
        int x = s[i] - '0';
        int add = (10 - x) % 10 * binpow(10, i);
        ans += add;
        n += add;
        i++;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}