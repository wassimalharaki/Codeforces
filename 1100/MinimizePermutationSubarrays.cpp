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

    vi nums(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a] = i;
    }
    
    if (nums[1] == 0 or nums[1] == n - 1) {
        cout << nums[2] + 1 << " " << (nums[1] == 0 ? n : 1) nl;
        return;
    }

    if (nums[n] != 0 and nums[n] != n - 1) {
        cout << nums[1] + 1 << " ";
        if (nums[2] > nums[n])
            cout << 1;
        else
            cout << n;
    }
    else {
        if (abs(nums[1] - nums[n]) < abs(nums[2] - nums[n]))
            cout << nums[1] + 1 << " " << nums[n] + 1;
        else
            cout << nums[2] + 1 << " " << nums[n] + 1;
    }
    cout nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while (T--)
        solve();

    return 0;
}