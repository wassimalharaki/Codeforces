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

    int min = INF, l, r;
    for (int i = 0; i < n - 1; i++)
        if (nums[i + 1] - nums[i] <= min) {
            min = nums[i + 1] - nums[i];
            l = i; r = i + 1;
        }
    
    cout << nums[l] << " ";
    for (int i = r + 1; i < n; i++)
        cout << nums[i] << " ";
    for (int i = 0; i < l; i++)
        cout << nums[i] << " ";
    cout << nums[r] nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}