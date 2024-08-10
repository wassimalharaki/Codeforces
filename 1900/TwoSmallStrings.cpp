#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

bool check(string& s, string& a, string& b) {
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        string t{s[i], s[i + 1]};
        if (t == a or t == b)
            return 0;
    }
    return 1;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if (s[0] != s[1] and t[0] != t[1]) {
        v<string> all{string(n, 'a'), string(n, 'b'), string(n, 'c')};
        do {
            string u = all[0] + all[1] + all[2];
            if (check(u, s, t)) {
                cout << "YES" << nl << u << nl;
                return;
            }
        } while (next_permutation(all.begin(), all.end()));
        cout << "NO" << nl;
    }
    if (s[0] == s[1] and t[0] == t[1]) {
        cout << "YES" << nl;
        for (int i = 0; i < n; i++)
            cout << "abc";
        cout << nl;
    }
    else {
        if (s[0] != s[1]) s.swap(t);
        if (t.find(s[0]) == -1) {
            cout << "YES" << nl;
            for (int i = 0; i < n; i++)
                cout << char('a' + (s[0] - 'a' + 1) % 3) << s[0];
            for (int i = 0; i < n; i++)
                cout << char('a' + (s[0] - 'a' + 2) % 3);
            cout << nl;
        }
        else {
            char other = 'a';
            if (s[0] == other or t[0] == other or t[1] == other)
                other++;
            if (s[0] == other or t[0] == other or t[1] == other)
                other++;

            cout << "YES" << nl;
            for (int i = 0; i < n; i++)
                cout << s[0] << other;
            for (int i = 0; i < n; i++)
                cout << (t[0] == s[0] ? t[1] : t[0]);
            cout << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}