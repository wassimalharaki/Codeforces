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
    int n, m; cin >> n >> m;

    vi a(n), answ(m);
    vpii b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i].F, b[i].S = i;
    sort(all(a)); sort(all(b));

    int count = 0, j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n and b[i].F >= a[j])
            j++, count++;
        answ[b[i].S] = count;
    }
    for (int i : answ)
        cout << i << " ";
}   

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}