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

    vi count(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x - 1] = i;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        int x = b[i] - a[i];
        if (x < 0)
            x += n;
        count[x]++;
    }

    cout << *max_element(all(count));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}