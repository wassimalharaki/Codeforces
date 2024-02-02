#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int a = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) continue;
        a++;
        if (i == n - 2) {
            if (s[i] == 'G')
                s[i + 1] = 'R';
            else
                s[i + 1] = 'G';
            continue;
        }

        if (s[i] == 'G') {
            if (s[i + 2] == 'G')
                s[i + 1] = 'R';
            else if (s[i + 2] == 'R')
                s[i + 1] = 'B';
            else
                s[i + 1] = 'R';
        }
        else if (s[i] == 'R') {
            if (s[i + 2] == 'G')
                s[i + 1] = 'B';
            else if (s[i + 2] == 'R')
                s[i + 1] = 'B';
            else
                s[i + 1] = 'G';
        }
        else {
            if (s[i + 2] == 'G')
                s[i + 1] = 'R';
            else if (s[i + 2] == 'R')
                s[i + 1] = 'G';
            else
                s[i + 1] = 'R';
        }
    }
    cout << a << nl << s << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}