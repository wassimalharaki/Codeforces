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
    string s; cin >> s;

    vi ok(n + 1);
    for (int i = 0; i < n; i++)
        ok[i + 1] = (s[i] == '1');
    
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        if (ok[i] == 1)
            continue;
        int c = (ok[i] == 0);
        for (int j = 2 * i; j <= n; j += i)
            if (ok[j] == 0)
                c++, ok[j] = -1;
            else if (ok[j] == 1)
                break;
        cost += c * i;
    }
    cout << cost nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}