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
    int n, s, k; cin >> n >> s >> k;

    vi nums(k);
    for (int i = 0; i < k; i++)
        cin >> nums[i];
    sort(all(nums));

    int i = 0;
    while (1) {
        if (s - i > 0) {
            auto it = lower_bound(all(nums), s - i);
            if (it == nums.end() or *it != s - i) {
                cout << i nl;
                return;
            }
        }

        if (s + i <= n) {
            auto it = lower_bound(all(nums), s + i);
            if (it == nums.end() or *it != s + i) {
                cout << i nl;
                return;
            }
        }
        i++;
    }
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while (T--)
        solve();

    return 0;
}