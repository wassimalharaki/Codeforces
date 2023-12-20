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

    int n, m; cin >> n >> m;

    vvi nums(n, vi(3));
    int sum_comp = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][1] >> nums[i][2];
        sum += nums[i][1];
        sum_comp += nums[i][2];
        nums[i][0] = nums[i][1] - nums[i][2];
    }
    sort(rall(nums));

    if (sum_comp > m) {
        cout << -1 nl;
        return 0;
    }

    int answ = 0, i = 0;
    while (sum > m) {
        sum -= nums[i++][0];
        answ++;
    }
    cout << answ nl;

    return 0;
}