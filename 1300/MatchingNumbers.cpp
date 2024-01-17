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

    if (!(n & 1)) {
        cout << "No" nl;
        return;
    }

    cout << "Yes" nl;
    int a = (n + 1) / 2, i = 1;
    for (; i <= a; i++)
        cout << i << " " << 2 * n - a + i nl;
    
    a = n / 2;
    for (int j = 0; j < a; j++, i++)
        cout << i << " " << i + n / 2 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}