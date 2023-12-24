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

    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            continue;
        if (l == -1)
            l = i;
        r = i;
    }

    int max = *max_element(a.begin() + l, a.begin() + r + 1);
    int min = *min_element(a.begin() + l, a.begin() + r + 1);

    while (l > 0 and a[l - 1] <= min) {
        l--;
        min = std::min(min, a[l]);
    }
    while (r + 1 < n and a[r + 1] >= max) {
        r++;
        max = std::max(max, a[r]);
    }
    cout << l + 1 << " " << r + 1 nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}