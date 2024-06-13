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

bool valid(string s, int p, int k) {
    int n = s.size();
    reverse(s.begin(), s.begin() + p);
    rotate(s.begin(), s.begin() + p, s.end());
    for (int i = 0; i < n - k; i++)
        if (s[i] == s[i + k])
            return 0;
    for (int i = 0; i < k; i++)
        if (s[i] != s[0])
            return 0;
    return 1;
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int z = count(s.begin(), s.end(), '0');
    if (z == 0 or z == n) {
        cout << (k == n ? n : -1) << nl;
        return;
    }

    if (k == n) {
        cout << -1 << nl;
        return;
    }

    if (valid(s, k, k)) {
        cout << k << nl;
        return;
    }

    int j = n - 1;
    while (s[j] == s[n - 1])
        j--;

    int curr = 1;
    for (int i = j - 1; i >= 0; i--)
        if (s[i] == s[i + 1]) {
            curr++;
            if (curr > k) {
                cout << (valid(s, i + 1, k) ? i + 1 : -1) << nl;
                return;
            }
        }
        else {
            if (curr != k) {
                cout << (valid(s, i + curr + 1, k) ? i + curr + 1 : -1) << nl;
                return;
            }
            curr = 1;
        }

    if (s[0] == s.back() and curr == k)
        curr = 2 * curr;
    cout << (valid(s, curr, k) ? curr : -1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}