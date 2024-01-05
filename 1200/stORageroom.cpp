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
 
    vvi nums(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];

    vi answ(n, (1 << 30) - 1);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            answ[i] &= nums[i][j], answ[j] &= nums[i][j];
    
    bool ok = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i][j] != (answ[i] | answ[j]))
                ok = 0;

    if (not ok) {
        cout << "NO" nl;
        return;
    }
    
    cout << "YES" nl;
    for (int i = 0; i < n; i++)
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