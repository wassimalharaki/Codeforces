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

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vi ops;
    bool flip = 0, ok = 1;
    int a = 0, b = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ok) {
            char c = s[b];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (c == t[i]) {
                b--;
                continue;
            }

            c = s[a];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (t[i] == c)
                ops.pb(1);
            ops.pb(i + 1);
            flip = !flip;
            ok = 0;
            a++;
        }
        else {
            char c = s[a];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (c == t[i]) {
                a++;
                continue;
            }

            c = s[b];
            if (flip)
                c = (c == '1' ? '0' : '1');

            if (t[i] == c)
                ops.pb(1);
            ops.pb(i + 1);
            flip = !flip;
            ok = 1;
            b--;
        }
    }

    cout << ops.size() << " ";
    for (int i = 0; i < ops.size(); i++)
        cout << ops[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}