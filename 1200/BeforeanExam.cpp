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
    int n, k; cin >> n >> k;

    int min = 0, max = 0;
    vpii nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].F >> nums[i].S;
        min += nums[i].F; max += nums[i].S;
    }

    if (k < min or k > max) {
        cout << "NO";
        return;
    }

    cout << "YES" nl;
    int spread = k - min;
    for (int i = 0; i < n; i++) {
        int sub = std::min(nums[i].S - nums[i].F, spread);
        cout << nums[i].F + sub << " ";
        spread -= sub;
    }
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}