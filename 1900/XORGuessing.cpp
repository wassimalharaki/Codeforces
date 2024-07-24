#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 14;
const int n = 100;

int ask(v<int>& a) {
    cout << "? ";
    for (int& x : a)
        cout << x << " ";
    cout << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    v<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    int x = ask(a);

    for (int& y : a) {
        bitset<N> bs(y);
        string s = bs.to_string();
        reverse(s.begin(), s.end());
        bs = bitset<N>(s);
        y = bs.to_ullong();
    }
    int y = ask(a);

    int ans = (x & ((1 << N) - (1 << 7))) | (y & ((1 << 7) - 1));
    cout << "! " << ans << endl;
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}