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
    v<string> grid(9);
    for (int i = 0; i < 9; i++)
        cin >> grid[i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            char& c = grid[3 * i + j][i + 3 * j];
            c = (c == '9' ? '1' : '9');
        }
    
    for (int i = 0; i < 9; i++)
        cout << grid[i] nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}