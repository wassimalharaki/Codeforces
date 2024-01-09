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
    sort(all(nums));

    queue<int> l;
    stack<int> r;

    for (int i = 0; i < n; i += 2) {
        if (i == n - 1) {
            l.push(nums[i]);
            continue;
        }
        l.push(nums[i]);
        r.push(nums[i + 1]);
    }
    while (not l.empty())
        cout << l.front() << " ", l.pop();
    while (not r.empty())
        cout << r.top() << " ", r.pop(); 
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}