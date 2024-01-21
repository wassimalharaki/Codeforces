#include <bits/stdc++.h>

using namespace std;

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
    v<string> s(2); cin >> s[0] >> s[1];
    
    int comp = count(all(s[0]), 'B') + count(all(s[1]), 'B');
    int curr = 0, row = -1, i = 0;
    for (; i < n; i++)
        if (s[0][i] == 'B' and s[1][i] != 'B') {
            row = 0;
            curr++;
            break;
        }
        else if (s[1][i] == 'B' and s[0][i] != 'B') {
            row = 1;
            curr++;
            break;
        }
        else
            curr += 2;

    while (++i < n) {
        if (s[row][i] != 'B')
            break;
        if (s[!row][i] == 'B')
            row = !row, curr++;
        curr++;
    }
    cout << (curr == comp ? "YES" : "NO") << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}