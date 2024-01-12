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
    int n, k; cin >> n >> k;

    vi nums(n);
    v<bool> p(n);
    for (int& a : nums) cin >> a;
    for (int i = 1; i < n - 1; i++)
        if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
            p[i] = 1;
    
    int max = 0, l = 1;
    for (int i = 1; i < k - 1; i++)
        max += p[i];
    
    int curr = max;
    for (int i = k; i < n; i++) {
        curr -= p[i - k + 1];
        curr += p[i - 1];
        if (curr > max)
            max = curr, l = i - k + 2;
    }
    cout << max + 1 << " " << l nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}