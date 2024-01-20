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

    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int i = 0; i < n; i++)
        if (a[i] > b[i]) {
            cout << "NO" << nl;
            return;
        }

    if (a[n - 1] != b[n - 1]) {
        int x = n - 1;
        for (int i = 0; i < n; i++)
            if (a[i] >= b[n - 1] - (i + 1)) {
                x = i;
                break;
            }
        
        for (int i = 0; i < x; i++)
            a[i] = b[n - 1] - (i + 1);
        a[n - 1] = b[n - 1];
    }

    for (int i = n - 1; i >= 0; i--)
        if (a[i] > b[i]) {
            cout << "NO" << nl;
            return;
        }
        else if (a[i] < b[i]) {
            if (a[i + 1] >= b[i] - 1)
                a[i] = b[i];
            else {
                cout << "NO" << nl;
                return;
            }
        }
    cout << "YES" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}