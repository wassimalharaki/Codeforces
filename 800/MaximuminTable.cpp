#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n; cin >> n;

    v<vi> table(n, vi(n, 1));
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            table[i][j] = table[i - 1][j] + table[i][j - 1];

    cout << table[n - 1][n - 1];

    return 0;
}