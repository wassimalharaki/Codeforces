#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vi a(n), b(n);
    a[0] = 1, b[0] = 1;
    bool hi = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == '2') {
            if (not hi)
                a[i] = 1, b[i] = 1;
            else
                b[i] = 2;
        }
        else if (s[i] == '1') {
            if (not hi)
                a[i] = 1, hi = 1;
            else
                b[i] = 1;
        }

    for (int i = 0; i < n; i++)
        cout << a[i];
    cout nl;
    for (int i = 0; i < n; i++)
        cout << b[i];
    cout nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}