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

    int n, m; cin >> n >> m;

    vi nums(n), left(n), right(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 1; i < n; i++)
        right[i] = max(nums[i - 1] - nums[i], (int) 0) + right[i - 1];
    
    for (int i = n - 2; i >= 0; i--)
        left[i] = max(nums[i + 1] - nums[i], (int) 0) + left[i + 1];

    while (m--) {
        int s, t; cin >> s >> t;
        s--, t--;
        s < t ? cout << right[t] - right[s] nl : cout << left[t] - left[s] nl;
    }

    return 0;
}