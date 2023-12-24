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
    

    vpii max(n + 1, mp(0, -1));
    for (int i = 0; i < n; i++) {
        int c = nums[i];
        if (max[c].S == -1) {
            max[c].S = i, max[c].F = 1;
            continue;
        }
        if ((i - max[c].S) & 1)
            max[c].F++, max[c].S = i;
    }

    for (int i = 1; i <= n; i++)
        cout << max[i].F << " ";
    cout nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}