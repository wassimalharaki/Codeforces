#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n, q; cin >> n >> q;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums), greater<int>());

    vi prefix(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = nums[i] + prefix[i];
    
    while (q--) {
        int x, y; cin >> x >> y;
        cout << prefix[x] - prefix[x - y] nl;
    }

    return 0;
}