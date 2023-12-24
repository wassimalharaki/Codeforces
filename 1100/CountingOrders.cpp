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

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;

    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(all(a)); sort(all(b));

    int count = 0;
    int answ = 1;
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 and a[j] > b[i])
            j--, count++;
        answ = (answ * (count - n + i + 1)) % mod;
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}