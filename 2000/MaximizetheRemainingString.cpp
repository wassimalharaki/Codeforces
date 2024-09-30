#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    string s; cin >> s;

    string t;
    while (s.size()) {
        int n = s.size();
        v<int> pref(n + 1), suff(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] | (1 << (s[i] - 'a'));
        for (int i = n - 1; i >= 0; i--)
            suff[i] = suff[i + 1] | (1 << (s[i] - 'a'));

        int j = -1;
        char c = '$';
        for (int i = 0; i < n; i++)
            if ((pref[i] & suff[i]) == pref[i])
                if (s[i] > c)
                    c = s[i], j = i;
        t += c;
        {
            string cln;
            for (int i = j + 1; i < n; i++)
                if (s[i] != c)
                    cln += s[i];
            s.swap(cln);
        }
    }
    cout << t << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}