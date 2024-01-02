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

vi prep(2 * 1e5);

void solve() {
    int n; cin >> n;

    int twos = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        twos += __builtin_ctzll(a);
    }

    vi can(prep.begin(), prep.begin() + n);
    sort(all(can), greater<int>());

    int ops = 0;
    for (int i = 0; i < n; i++)
        if (can[i] and twos + can[i] <= n)
            twos += can[i], ops++;
    cout << (twos >= n ? ops : -1) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 2 * 1e5; i++)
        prep[i] = __builtin_ctzll(i + 1);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}