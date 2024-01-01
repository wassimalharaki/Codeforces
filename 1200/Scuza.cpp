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
    int n, q; cin >> n >> q;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vpii queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i].F, queries[i].S = i;
    sort(all(queries));

    vi answ(q);
    int sum = 0, j = 0;
    for (int i = 0; i < q; i++) {
        while (j < n and queries[i].F >= nums[j])
            sum += nums[j++];
        answ[queries[i].S] = sum;
    }

    for (int i = 0; i < q; i++)
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