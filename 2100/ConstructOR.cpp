#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 60;

int get(int a, int d) {
    int x = 0, lsb = __builtin_ctz(d);
    for (int i = 0; i < N / 2; i++)
        if (((1 << i) & a) and !((1 << i) & x))
            x += d << (i - lsb);
    return x;
}

void solve() {
    int a, b, d; cin >> a >> b >> d;
    int lsb = __builtin_ctz(d);
    if (__builtin_ctz(a) < lsb)
        return void(cout << -1 << nl);
    if (__builtin_ctz(b) < lsb)
        return void(cout << -1 << nl);
    cout << get(a | b, d) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}