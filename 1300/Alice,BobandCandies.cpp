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
    for (int& a : nums) cin >> a;

    int l = 1, r = n - 1;
    int a = nums[0], b = 0, m = 1;
    int atot = nums[0], btot = 0;
    bool alt = 1;
    while (l <= r) {
        m++;
        if (alt) {
            b = 0;
            while (r >= l and b <= a)
                b += nums[r--];
            btot += b;
        }
        else {
            a = 0;
            while (l <= r and a <= b)
                a += nums[l++];
            atot += a;
        }
        alt = !alt;
    }
    cout << m << " " << atot << " " << btot nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}