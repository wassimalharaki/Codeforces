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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    v<int> nums(k, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') continue;
        int ok = s[i] - '0';
        int& a = nums[i % k];
        if (a == -1 or a == ok)
            a = ok;
        else {
            cout << "NO" << nl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        int& a = nums[i % k];
        if (a == -1) continue;
        s[i] = '0' + a;
    }

    v<int> cnt(2);
    for (int i = 0; i < k; i++)
        if (s[i] != '?')
            cnt[s[i] - '0']++;

    if (cnt[0] > k / 2 or cnt[1] > k / 2) {
        cout << "NO" << nl;
        return;
    }

    for (int i = k; i < k; i++) {
        if (s[i - k] != '?')
            cnt[s[i - k] - '0']--;
        if (s[i] != '?')
            cnt[s[i] - '0']++;
        if (cnt[0] > k / 2 or cnt[1] > k / 2) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}