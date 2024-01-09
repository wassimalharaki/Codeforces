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

    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a == 1 ? one++ : two++;
    }
    if (two)
        cout << 2 << " ", two--;

    if (one & 1) {
        while (one--)
            cout << 1 << " ";
        while (two--)
            cout << 2 << " ";
    }
    else {
        one--;
        while (one-- > 0)
            cout << 1 << " ";
        while (two--)
            cout << 2 << " ";
        if (one == -1) cout << 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}