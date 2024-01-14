#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define dbg(x) cerr << #x << " " << x nl;
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
    int n, m; cin >> n >> m;

    vvi nums(n, vi(m));
    for (vi& a : nums)
        for (int& b : a)
            cin >> b;
    
    vvi answ(n, vi(m, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (nums[i][j]) continue;
            for (int k = 0; k < m; k++)
                answ[i][k] = 0;
            for (int k = 0; k < n; k++)
                answ[k][j] = 0;
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a = 0;
            for (int k = 0; k < m; k++)
                a |= answ[i][k];
            for (int k = 0; k < n; k++)
                a |= answ[k][j];
            if (a != nums[i][j]) {
                cout << "NO";
                return;
            }
        }
    
    cout << "YES" nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << answ[i][j] << " ";
        cout nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}