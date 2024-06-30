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

const int N = 26;

void solve() {
    string s; cin >> s;

    array<int, N> cnt; cnt.fill(0);
    for (char& c : s)
        cnt[c - 'a']++;

    int x = - (s.size() & 1);
    for (int i = 0; i < N; i++)
        x += cnt[i] & 1;
    
    int r = x / 2, l = x / 2;
    for (int i = 0; i < N and l; i++)
        if (cnt[i] & 1)
            cnt[i]++, l--;
    for (int i = N - 1; i >= 0 and r; i--)
        if (cnt[i] & 1)
            cnt[i]--, r--;

    string t, mid;
    for (int i = 0; i < N; i++) {
        t += string(cnt[i] / 2, char('a' + i));
        if (cnt[i] & 1) mid = string{char('a' + i)};
        cnt[i] >>= 1;
    }
    t += mid;
    for (int i = N - 1; i >= 0; i--)
        t += string(cnt[i], char('a' + i));
    cout << t << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}