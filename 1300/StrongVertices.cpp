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


//au - bu >= av - bv
void solve() {
    int n; cin >> n;

    vi a(n), b(n);
    for (int& c : a) cin >> c;
    for (int& c : b) cin >> c;

    vi nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = a[i] - b[i];
    sort(all(nums));

    vi answ;
    for (int i = 0; i < n; i++) {
        int c = upper_bound(all(nums), a[i] - b[i]) - ++nums.begin();
        if (c == n - 1) answ.pb(i + 1);
    }
    sort(all(answ));

    cout << answ.size() nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}