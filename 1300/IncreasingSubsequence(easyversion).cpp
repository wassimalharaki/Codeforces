#include <bits/stdc++.h>

using namespace std;

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

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int i = 0, j = n - 1, prev = -1;
    string s;
    auto left = [&]() -> void {
        s.pb('L');
        prev = nums[i];
        i++;
    };
    auto right = [&]() -> void {
        s.pb('R');
        prev = nums[j];
        j--;
    };

    nums[i] < nums[j] ? left() : right();
    while (i <= j)
        if (nums[i] < prev and nums[j] < prev)
            break;
        else if (nums[i] > prev and nums[j] < prev)
            left();
        else if (nums[i] < prev and nums[j] > prev)
            right();
        else if (nums[i] > nums[j])
            right();
        else
            left();
    cout << s.size() << nl << s;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}