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
    int m, s; cin >> m >> s;
    int s1 = s;
 
    if (s == 0 and m > 1) {
        cout << "-1 -1";
        return;
    }
 
    if (s == 0) {
        cout << "0 0";
        return;
    }
 
    if (s > 9 * m) {
        cout << "-1 -1";
        return;
    }
 
    string min(m, '0'), max(m, '0');
    if (s <= 9 * (m - 1))
        min[0] = '1', s--;
    for (int i = m - 1; i >= 0 and s; i--) {
        char c = (s >= 9 ? '9' : '0' + s);
        s -= std::min(s, 9ll);
        min[i] = c;
    }
 
    for (int i = 0; i < m; i++) {
        char c = (s1 >= 9 ? '9' : '0' + s1);
        s1 -= std::min(s1, 9ll);
        max[i] = c;
    }
 
    cout << min << " " << max;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}