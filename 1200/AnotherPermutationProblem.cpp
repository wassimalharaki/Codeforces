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

    vi perm(n);
    iota(all(perm), 1ll);

    int answ = 0;
    for (int i = 0; i < n; i++) {
        vi nums(perm);
        reverse(i + all(nums));
        int max = 0, sum = 0;
        for (int j = 0; j < n; j++)
            sum += (j + 1) * nums[j],
            max = std::max(max, (j + 1) * nums[j]);
        answ = std::max(answ, sum - max);
    }
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