#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(rall(a)); sort(rall(b));

    int k = n, c = 3 * (k + 1) / 4, j = c - 1;
    int suma = 0, sumb = 0;
    for (int i = 0; i < c; i++)
        suma += a[i], sumb += b[i];

    while (suma < sumb) {
        k++;
        if (k % 4 == 0)
            suma += (j >= 0 ? 100 - a[j--] : 0);
        else
            suma += 100,
            sumb += (c < n ? b[c++] : 0);
    }
    cout << k - n nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}