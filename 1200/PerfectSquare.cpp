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
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            nums[i][j] = c - 'a';
        }
    
    int answ = 0;
    for (int i = 0; i < n / 2; i++) {
        int a = n - i - 1;
        for (int j = i; j < a; j++) {
            int b = n - j - 1;
            vi curr{
                nums[i][j],
                nums[j][a],
                nums[a][b],
                nums[b][i],
            };
            sort(all(curr));
            for (int k = 0; k < 3; k++)
                answ += curr[3] - curr[k];
        }
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