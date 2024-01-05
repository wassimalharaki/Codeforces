#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    if (nums.size() == 3 and nums[1] & 1) {
        cout << -1 nl;
        return;
    }

    if (count(nums.begin() + 1, nums.end() - 1, 1ll) == n - 2) {
        cout << -1 nl;
        return;
    }

    int answ = 0;
    for (int i = 1; i < n - 1; i++)
        answ += (nums[i] + 1) / 2;
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}