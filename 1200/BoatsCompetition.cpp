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
    sort(all(nums));

    v<set<int>> sums(101, set<int>());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if (sums[sum].find(j) != sums[sum].end()
                    or sums[sum].find(i) != sums[sum].end())
                continue;
            sums[sum].insert(j);
            sums[sum].insert(i);
        }

    int max = 0;
    for (int i = 0; i < 101; i++)
        max = std::max(max, (int) sums[i].size());
    cout << max / 2 nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}