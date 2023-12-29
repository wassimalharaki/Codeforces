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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int i = 0; i < (1 << n); i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
            (1 << j) & i ? sum1 += nums[j] : sum2 += nums[j];
        sum1 %= 360, sum2 %= 360;
        if (sum1 == sum2) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}