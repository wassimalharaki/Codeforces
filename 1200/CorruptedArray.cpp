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

    vi nums(n + 2);
    for (int i = 0; i < n + 2; i++)
        cin >> nums[i];
    sort(all(nums));

    int sum = accumulate(all(nums), 0ll);
    for (int i = 0; i < n + 2; i++) {
        int x = i;
        int max = (i == n + 1 ? n : n + 1);
        if (sum - nums[x] - nums[max] == nums[max]) {
            for (int j = 0; j < n + 2; j++)
                if (j != x and j != max)
                    cout << nums[j] << " ";
            cout nl;
            return;
        } 
    }
    cout << -1 nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}