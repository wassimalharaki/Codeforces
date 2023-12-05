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

int32_t main() {
    fast;

    int n; cin >> n;

    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F , nums[i].S = i;
    sort(all(nums));

    int m; cin >> m;

    int beg = 0, end = 0;
    while (m--) {
        int a; cin >> a;
        auto it = lower_bound(all(nums), (pii) mp(a, -1));
        beg += it -> second + 1;
        end += n - it -> second;
    }
    cout << beg << " " << end;

    return 0;
}