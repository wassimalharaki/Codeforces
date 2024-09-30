#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;

array<int, 3> get(string& s) {
    array<int, 3> a{0, 0, 0};
    for (char& c : s)
        if (c == 'a')
            a[0]++;
        else if (c == 'b')
            a[1] += a[0];
        else
            a[2] += a[1];
    return a;
}

array<int, 3> dfs(string& s, int i) {
    if (i == (int) s.size())
        return get(s);
    if (s[i] != '?')
        return dfs(s, i + 1);
    else {
        array<int, 3> a{0, 0, 0};
        for (char c = 'a'; c <= 'c'; c++) {
            s[i] = c;
            auto x = dfs(s, i + 1);
            a[0] += x[0];
            a[1] += x[1];
            a[2] += x[2];
        }
        s[i] = '?';
        return a;
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int k = 1;
    array<int, 3> a{0, 0, 0};
    for (char& c : s)
        if (c == 'a')
            a[0] = (a[0] + k) % mod;
        else if (c == 'b')
            a[1] = (a[1] + a[0]) % mod;
        else if (c == 'c')
            a[2] = (a[2] + a[1]) % mod;
        else {
            a[2] = (3 * a[2] + a[1]) % mod;
            a[1] = (3 * a[1] + a[0]) % mod;
            a[0] = (3 * a[0] + k) % mod;
            k = k * 3 % mod;
        }
    cout << a[2] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}