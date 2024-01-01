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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int lo = 1, hi = 1e18, answ;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int dmg = mid;
        for (int i = 1; i < n; i++) {
            dmg += min(mid, nums[i] - nums[i - 1]);
            if (dmg >= k)
                break;
        }
        
        if (dmg >= k)
            answ = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}