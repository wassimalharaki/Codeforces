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

    vi correct(n), wrong(m);
    for (int i = 0; i < n; i++)
        cin >> correct[i];
    for (int i = 0; i < m; i++)
        cin >> wrong[i];
    sort(all(correct)); sort(all(wrong));

    int lo = correct[n - 1], hi = wrong[0] - 1, answ = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        bool ok = 0;
        for (int i = 0; i < n; i++)
            if (correct[i] * 2 <= mid)
                ok = 1;
        
        if (ok)
            answ = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}