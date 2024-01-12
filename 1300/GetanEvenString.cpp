#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

int bruteforce(string s) {
    int n = s.size(), answ = n;
    for (int mask = 0; mask < (1 << n); mask++) {
        vi dead(n);
        for (int i = 0; i < n; i++)
            if ((1 << i) & mask)
                dead[i] = 1;
        string t;
        for (int i = 0; i < n; i++)
            if (not dead[i])
                t.pb(s[i]);
        int c = 1;
        bool ok = 1;
        for (int i = 1; i < t.size(); i++)
            if (t[i] == t[i - 1]) c++;
            else if (c & 1) ok = 0;
            else c = 1;
        if (not ok or c & 1) continue;
        answ = min(answ, (int) __builtin_popcountll(mask));
    }
    return answ;
}

void solve() {
    string s; cin >> s;

    vi letters(26);
    int answ = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        letters[c]++;
        if (!(letters[c] & 1)) {
            for (int j = 0; j < 26; j++)
                answ += letters[j] & 1;
            fill(all(letters), 0ll);
        }
    }
    for (int j = 0; j < 26; j++)
        answ += letters[j] & 1;
    fill(all(letters), 0ll);
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}