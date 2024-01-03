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

    vi ok1(n);
    vi ok2(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int j; cin >> j; j--;
            if (ok2[i])
                continue;
            if (not ok1[j])
                ok2[i] = 1, ok1[j] = 1;
        }
    }
    int g = -1, b = -1;
    for (int i = 0; i < n; i++) {
        if (ok2[i] == 0)
            g = i;
        if (ok1[i] == 0)
            b = i;
    }
    if (g != -1)
        cout << "IMPROVE" nl << g + 1 << " " << b + 1 nl;
    else
        cout << "OPTIMAL" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}