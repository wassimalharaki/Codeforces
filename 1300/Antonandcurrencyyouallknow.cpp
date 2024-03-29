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
    string s; cin >> s;
    int n = s.size();

    bool ok = 0;
    for (int i = 0; i < n; i++)
        if (!((s[i] - '0') & 1))
            ok = 1;

    if (not ok) {
        cout << -1;
        return;
    }

    int k;
    for (int i = 0; i < n; i++)
        if (!((s[i] - '0') & 1)) {
            if (s[n - 1] > s[i]) {
                swap(s[n - 1], s[i]);
                cout << s;
                return;
            }
            k = i;
        }
    swap(s[k], s[n - 1]);
    cout << s;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}