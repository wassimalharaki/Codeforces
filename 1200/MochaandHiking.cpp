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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    if (nums[0]) {
        cout << n + 1;
        for (int i = 1; i <= n; i++)
            cout << " " << i;
        cout nl;
        return;
    }
    if (nums[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++)
            cout << i << " ";
        cout nl;
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] or not nums[i + 1])
            continue;
        for (int j = 1; j <= i + 1; j++)
            cout << j << " ";
        cout << n + 1;
        for (int j = i + 2; j <= n; j++)
            cout << " " << j;
        cout nl;
        return;
    }
    
    cout << -1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}