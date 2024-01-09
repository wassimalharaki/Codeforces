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
    int n = s.size(), answ = 0;

    vi l;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            l.pb(i);
            continue;
        }
        answ++;

        int r = i + 2;
        while (not l.empty() and r < n)
            if (s[l[l.size() - 1]] == s[r]) {
                l.pop_back(), r++;
                answ++;
            }
            else
                break;
        i = r - 1;
    }
    cout << (answ & 1 ? "Yes" : "No") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}