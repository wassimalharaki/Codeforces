#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

/*
5 2 1 3 7 6 4
L = 4, R = 4
7 6 4 3 5 2 1
*/

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int find = n;
    if (nums[0] == find) find--;

    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
        if (nums[i] == find) l = i - 1, r = i - 1;
    
    if (l == n - 2)
        l = n - 1, r = n - 1;
    
    while (l and nums[l - 1] > nums.front())
        l--;
    reverse(l + all(nums) - (n - r - 1));

    for (int i = r + 1; i < n; i++)
        cout << nums[i] << " ";
    for (int i = l; i <= r; i++)
        cout << nums[i] << " ";
    for (int i = 0; i < l; i++)
        cout << nums[i] << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}