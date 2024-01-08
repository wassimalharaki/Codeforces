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
    int n, x; cin >> n >> x;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    if (x <= n / 2) {
        cout << "YES" nl;
        return;
    }
    
    vi a;
    for (int i = 0; i < n; i++)
        if (i + x < n)
            a.pb(nums[i]), a.pb(nums[i + x]);
    sort(all(a));

    vi res(n);
    int j = 0;
    for (int i = 0; i < a.size() / 2; i++)
        res[j++] = a[i];
    
    for (; j < n - a.size() / 2; j++)
        res[j] = nums[j];
    
    for (int i = a.size() / 2; i < a.size(); i++)
        res[j++] = a[i];

    cout << (is_sorted(all(res)) ? "YES" : "NO") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}